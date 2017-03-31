#pragma once
#pragma execution_character_set("utf-8")

#include<iostream>
#include "../lib/libwebsockets.h"

#include "./commmon_data/common_data.h"
#include "./handler/http_handler.h"

extern "C"
{
#include "gettimeofday.h"
}
int debug_level = 7;
struct lws_context *context;
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

	//������־����
	lws_set_log_level(debug_level, lwsl_emit_syslog);

	info.iface = iface;
	info.protocols = protocols;
	info.ssl_cert_filepath = NULL;
	info.ssl_private_key_filepath = NULL;
	info.ws_ping_pong_interval = pp_secs;
	info.gid = gid;//��ID������Ҫʱ������-1
	info.uid = uid;//�û�ID������Ҫʱ������-1
	info.max_http_header_pool = 16;//ͬʱ������������httpͷ�����������������Ҫ�ȴ�
	info.options = opts | LWS_SERVER_OPTION_VALIDATE_UTF8;//LWS_SERVER_OPTION_VALIDATE_UTF8���UTF8����ȷ��,
	info.extensions = NULL;//exts; ?
	info.timeout_secs = 5;//�����л�����ÿ�ιҶϵĳ�ʱʱ��
	info.ssl_cipher_list = "ECDHE-ECDSA-AES256-GCM-SHA384:"
		"ECDHE-RSA-AES256-GCM-SHA384:"
		"DHE-RSA-AES256-GCM-SHA384:"
		"ECDHE-RSA-AES256-SHA384:"
		"HIGH:!aNULL:!eNULL:!EXPORT:"
		"!DES:!MD5:!PSK:!RC4:!HMAC_SHA1:"
		"!SHA1:!DHE-RSA-AES128-GCM-SHA256:"
		"!DHE-RSA-AES128-SHA256:"
		"!AES128-GCM-SHA256:"
		"!AES128-SHA256:"
		"!DHE-RSA-AES256-SHA256:"
		"!AES256-GCM-SHA384:"
		"!AES256-SHA256";

	//����һ��web socket ������
	//lws_create_context ����һ�������׽��֣�������񣩲������ʼ����
	context = lws_create_context(&info);


	n = 0;
	while (n >= 0)
	{
		struct timeval tv;

		gettimeofday(&tv, NULL);

		/*
		* This provokes the LWS_CALLBACK_SERVER_WRITEABLE for every
		* live websocket connection using the DUMB_INCREMENT protocol,
		* as soon as it can take more packets (usually immediately)
		*/
		ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		if ((ms - oldms) > 50) {
			lws_callback_on_writable_all_protocol(context,
				&protocols[PROTOCOL_DUMB_INCREMENT]);
			oldms = ms;
		}

		//Ϊδ����websocket����
		// @context Websocket context
		// @50 ��ʱʱ����룬���Ϊ0�ڲ���Ҫ�������������������أ������Ҫ��������ֹ���з���
		n = lws_service(context, 50);

	}
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