import socket

with open("server_ip.txt") as f: # read the server ip from a file, placed in the same directory
    ip_address = f.read().strip()
port = 1337
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((ip_address, port))

def raise_exception(e: Exception, message: str, raise_except: bool) -> None:
    """raises the message as exception if raise_except. Otherwise prints it."""
    exception_message = f"Fehler: {message} {e}"
    if raise_except:
        raise Exception(exception_message)
    else:
        print(exception_message)

def send_message(message: str) -> None:
    """sends a pixel in the message coordinates and RGB color. Format needs to be 'PX X Y RGB'"""
    s.sendall(message.encode())
    
def send_pixel(x: int, y: int, rgb: str, raise_except: bool = False) -> None:
    """sends a pixel in the RGB color"""
    message= f"PX {x} {y} " + rgb + "\n"
    try:
        send_message(message)
    except Exception as e:
        raise_exception(e, message, raise_except)
    
def send_pixel_int(x: int, y: int, r: int, g: int, b: int, raise_except: bool = False) -> None:
    """sends a pixel in the RGB color"""
    send_pixel(x, y, f"{r:02X}{g:02X}{b:02X}", raise_except)

def get_hex_color(x: int, y: int, raise_except: bool = False) -> str:
    """gets a pixels RGB color as hex string"""
    message = f'PX {x} {y}\r\n'
    try:
        s.sendall(message.encode())
    except Exception as e:
        raise_exception(e, message, raise_except)
    #Länge vom String + Leerzeichen + RGB-Hexcode)
    expected_message_length = len(f'{message} ffffff'.encode())
    response = b""
    while len(response) < expected_message_length:
        response += s.recv(expected_message_length)
    return response.decode().split()[3]

def get_color(x: int, y: int, raise_except: bool = False) -> tuple[int, int, int]:
    """gets a pixels rgb color as RGB decimal numbers"""
    response = get_hex_color(x, y, raise_except)
    r = int(response[0:2], 16)
    g = int(response[2:4], 16)
    b = int(response[4:6], 16)
    return r, g, b
