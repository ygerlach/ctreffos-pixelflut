// does the server support the binary protocol?
#define BINPROT 1

// does the server support the offset command?
#define OFFSET 1

// wait after each print for x ms
#define SPEEDLIMIT 10

//const char* server_ip = "151.216.224.25";
const char* server_ip = "151.216.224.48";

//const char* server_ip = "151.219.62.20";
//const char* server_ip = "2001:67c:20a1:1561:e61d:2dff:fe4c:f6e1";
//const char* server_ip = "151.219.13.247";
const sa_family_t family = AF_INET;
#define sockaddr_AF sockaddr_in

// uint16_t server_port = 1337;
uint16_t server_port = 1234;
const char* image = "ctreffos-logo-square-whitetext_small.png";