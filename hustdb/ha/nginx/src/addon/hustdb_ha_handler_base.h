#ifndef __hustdb_ha_handler_base_20150605184922_h__
#define __hustdb_ha_handler_base_20150605184922_h__

#include "hustdb_ha_table_def.h"

typedef struct
{
    ngx_http_subrequest_ctx_t base;
    ngx_http_subrequest_peer_t * peer;
    const char * key;
    const char * tb;
    ngx_bool_t key_in_body;
    const ngx_str_t * version;
} hustdb_ha_ctx_t;

typedef struct
{
    ngx_http_subrequest_ctx_t base;
    ngx_http_upstream_rr_peer_t * peer;
} hustdb_ha_loop_ctx_t;

typedef struct
{
    ngx_http_subrequest_ctx_t base;
    const ngx_str_t * keys;
} hustdb_ha_peer_ctx_t;

ngx_int_t hustdb_ha_send_response(
        ngx_uint_t status,
        const ngx_str_t * version,
        const ngx_str_t * response,
        ngx_http_request_t *r);

ngx_int_t hustdb_ha_on_subrequest_complete(ngx_http_request_t * r, void * data, ngx_int_t rc);

typedef ngx_bool_t (*hustdb_ha_check_parameter_t)(ngx_str_t * backend_uri, ngx_http_request_t *r);
ngx_int_t hustdb_ha_post_peer(
    hustdb_ha_check_parameter_t check_parameter,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

ngx_int_t hustdb_ha_read_handler(
    ngx_bool_t read_body,
    ngx_bool_t key_in_body,
    hustdb_ha_check_parameter_t check_parameter,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

ngx_int_t hustdb_ha_loop_handler(
    hustdb_ha_check_parameter_t check_parameter,
    ngx_str_t * backend_uri,
    ngx_http_request_t *r);

typedef struct
{
    ngx_http_subrequest_peer_t * peer;
    size_t bucket;
    int bad_buckets;
} hustdb_ha_bucket_buf_t;

ngx_bool_t hustdb_ha_get_readable_peer(size_t buckets, size_t bucket, hustdb_ha_bucket_buf_t * result);
ngx_bool_t hustdb_ha_init_identifier_cache(ngx_http_hustdb_ha_main_conf_t * mcf);

#endif // __hustdb_ha_handler_base_20150605184922_h__
