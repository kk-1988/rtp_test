#include <stdio.h>

#pragma pack(1)

typedef struct RTP_FIXED_HEADER{
    /* byte 0 */
    unsigned char csrc_len:4;
    unsigned char extension:1;
    unsigned char padding:1;
    unsigned char verson:2;

    /* byte1 */
    unsigned char payload:7;
    unsigned char marker:1;

    /* byte2,3 */
    unsigned short seq_no;

    /* btte4-7 */
    unsigned long timestamp;

    /* bytes 8-11 */
    unsigned long ssrc;
};

typedef struct MPEGTS_FIXED_HEADER{
    unsigned sync_byte:8;
    unsigned transport_error_indicator:1;
    unsigned payload_unit_start_indicator:1;
    unsigned transport_priority:1;
    unsigned PID:13;
    unsigned scrambling_control:2;
    unsigned adaptation_field_exist:2;
    unsigned continuity_counter:4;
}MPEGTS_FIXED_HEADER;

int simplest_udp_parser(int port)
{
    int cnt = 0;
    int sock;

    FILE *myout = stdout;

    FILE *fp1 = fopen("output_dump.ts","wb+");

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock < 0)
    {
        printf("create socket error...\r\n");
        return -1;
    }

    sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if(bind(sock, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR){
		printf("bind error !");
		close(sock);
		return -1;
	}

    


}

int main(int argc,char *argv[])
{
    printf("simplest_udp_parser demo...\r\n");
    simplest_udp_parser(8880);

    return 0;
}