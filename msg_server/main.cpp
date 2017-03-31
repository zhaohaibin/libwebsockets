#pragma once
#pragma execution_character_set("utf-8")

#include<iostream>
#include "../lib/libwebsockets.h"

void msg_server()
{
	//lws_context_creation_info 用于创建虚拟主机，如果lws_server_option_explicit_vhosts没有给出，为了向后兼容，将会使用lws_context_creation_info创建虚机
	//如果lws_server_option_explicit_vhosts已给定，同时没有虚机用lws_context_creation_info创建，虚机之后将会被创建
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

	//设置监听端口，使用CONTEXT_PORT_NO_LISTEN阻止对客户端的监听
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