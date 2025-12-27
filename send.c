#include "unistd.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "stdio.h"
#include "string.h"
#include "errno.h"
#include <fcntl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int speed = 3;
int vx = 1;
int vy = 1;
int posx = 0;
int posy = 0;

int cr = 0;
int cg = 120;
int cb = 250;
int r = 1;
int g = -1;
int b = 1;

int imgW = 10;
int imgH = 10;
int w = 1920;
int h = 1080;

int s = -1;
const char* server_ip = "151.219.13.203";
uint16_t server_port = 1234;
const char* image = "ctreffos-logo-square-whitetext_small.png";

int main() {
    s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(server_port);
    inet_aton(server_ip, &serv.sin_addr);
    int con = connect(s, (struct sockaddr*) &serv, sizeof(serv));
    printf("%d %s\n", con, strerror(errno));

    fcntl(s, F_SETFL, O_NONBLOCK);

    static const long opt = 1<<20;
    setsockopt(s, SOL_SOCKET, SO_SNDBUF, &opt, sizeof(opt));

    int imgW, imgH, n;
    unsigned char *data = stbi_load(image, &imgW, &imgH, &n, 2);
    
    printf("image width: %i image Height: %i image components: %i \n", imgW, imgH, n);

    int size_of_pixel = 2;
    int size_of_line = size_of_pixel * imgW;

    char buffer[32];
    // init buffer
    snprintf(buffer, sizeof(buffer), "PX ");

    while(1) {
        char colorBuf[12];
        int colorLen = snprintf(colorBuf, sizeof(colorBuf), " %02x%02x%02x\r\n", cr, cg, cb);

        for(int y = 0; y < imgH; ++y) {
            char* line = data + y * size_of_line;
            
            for(int x = 0; x < imgW; ++x) {
                char* pxl = line + x * size_of_pixel;
                if(pxl[n-1] != 0) {
                    int length = snprintf(buffer+3, sizeof(buffer)-3, "%d %d%s", x+posx, y+posy, colorBuf);

                    const char* buffCopy = buffer;
                    int lengthCopy = length+3;
                    do {
                        ssize_t wc = write(s, buffCopy, lengthCopy);
                        if(wc == lengthCopy) {
                            break;
                        }

                        if(errno == EAGAIN || errno == EWOULDBLOCK) {
                            usleep(1);
                        }

                        if(errno != EAGAIN && errno != EWOULDBLOCK  && errno != 0) {
                            printf("error writing: %i\n", errno);
                            return 1;
                        }

                        if(wc > 0) {
                            lengthCopy -= wc;
                            buffCopy += wc;
                        }
                    }
                    while(lengthCopy > 0);
                }
            }
        }

        posx += vx;
        posy += vy;

        if (posx + imgW >= w)
            vx *= -1;
        if (posx <= 0)
            vx *= -1;

        if (posy + imgH >= h)
            vy *= -1;
        if(posy <= 0)
            vy *= -1;

        if (r == 1 && cr > 255-speed)
            r = -1;
        if (cr < speed && r == -1)
            r = 1;

        if (g == 1 && cg > 255-speed)
            g = -1;
        if (cg < speed && g == -1)
            g = 1;

        if (b == 1 && cb > 255-speed)
            b = -1;
        if (cb < speed && b == -1)
            b = 1;

        cr += r * speed;
        cg += g * speed;
        cb += b * speed;
    }

    printf("end\n");

    return 0;
}
