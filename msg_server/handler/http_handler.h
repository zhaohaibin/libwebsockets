#pragma once;
#include "../commmon_data/common_data.h"

enum demo_protocols {
	/* always first */
	PROTOCOL_HTTP = 0,

	PROTOCOL_DUMB_INCREMENT,//dumb-increment-protocol (simple streaming incrementing numbers)
	PROTOCOL_LWS_MIRROR,

	/* always last */
	DEMO_PROTOCOL_COUNT
};

int callback_http(struct lws *wsi, enum lws_callback_reasons reason, void *user,
	void *in, size_t len);

static struct lws_protocols protocols[] = {
	/* first protocol must always be HTTP handler */

	{
		"http-only",		/* name */
		callback_http,		/* callback */
		sizeof(struct per_session_data__http),	/* per_session_data_size */
		0,			/* max frame size / rx buffer */
	},
	// 	{
	// 		"dumb-increment-protocol",
	// 		callback_dumb_increment,
	// 		sizeof(struct per_session_data__dumb_increment),
	// 		10, /* rx buf size must be >= permessage-deflate rx size */
	// 	},
	// 	{
	// 		"lws-mirror-protocol",
	// 		callback_lws_mirror,
	// 		sizeof(struct per_session_data__lws_mirror),
	// 		128, /* rx buf size must be >= permessage-deflate rx size */
	// 	},
	// 	{
	// 		"lws-echogen",
	// 		callback_lws_echogen,
	// 		sizeof(struct per_session_data__echogen),
	// 		128, /* rx buf size must be >= permessage-deflate rx size */
	// 	},
	// 	{
	// 		"lws-status",
	// 		callback_lws_status,
	// 		sizeof(struct per_session_data__lws_status),
	// 		128, /* rx buf size must be >= permessage-deflate rx size */
	// 	},
	{ NULL, NULL, 0, 0 } /* terminator */
};
