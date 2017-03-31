#pragma once
#pragma execution_character_set("utf-8")

#include<iostream>
#include "../lib/libwebsockets.h"

void msg_server()
{
	//lws_context_creation_info ���ڴ����������������lws_server_option_explicit_vhostsû�и�����Ϊ�������ݣ�����ʹ��lws_context_creation_info�������
	//���lws_server_option_explicit_vhosts�Ѹ�����ͬʱû�������lws_context_creation_info���������֮�󽫻ᱻ����
	struct lws_context_creation_info info;

	char interface_name[128] = "";
	unsigned int ms, oldms = 0;
	const char *iface = NULL;
	char cert_path[1024] = "";
	char key_path[1024] = "";
	char ca_path[1024] = "";
	int uid = -1, gid = -1;
	int use_ssl = 0;
	int pp_secs = 0;
	int opts = 0;
	int n = 0;
	memset(&info, 0, sizeof info);

	//���ü����˿ڣ�ʹ��CONTEXT_PORT_NO_LISTEN��ֹ�Կͻ��˵ļ���
	info.port = 7681;
}

bool run = true;
int main(int argc, char **argv)
{
	msg_server();
	while ( run )
	{

	}
	return 0;
}