#include <ruby.h>
#include <netinet/in.h>
#include <spf2/spf.h>
#include <spf2/spf_server.h>

static VALUE spf2_set_debug(VALUE self, VALUE bDebug)
{
    SPF_server_t *spf_server;

    Data_Get_Struct(self, SPF_server_t, spf_server);
    spf_server->debug = RTEST(bDebug);


    return self;
}

static VALUE spf2_query(VALUE self, VALUE ipfrom, VALUE domain)
{

    SPF_server_t *spf_server = NULL;
    SPF_response_t *spf_response = NULL;
    SPF_request_t *spf_request = NULL;

    VALUE ret, str_result, str_reason, str_error;

    Data_Get_Struct(self, SPF_server_t, spf_server);

    spf_request = SPF_request_new(spf_server);

    SPF_request_set_ipv4_str(spf_request, StringValueCStr(ipfrom));
    SPF_request_set_env_from(spf_request, StringValueCStr(domain));
    SPF_request_query_mailfrom(spf_request, &spf_response);

    str_result =
	rb_str_new2(SPF_strresult(SPF_response_result(spf_response)));
    str_reason =
	rb_str_new2(SPF_strreason(SPF_response_reason(spf_response)));
    str_error =
	rb_str_new2(SPF_strerror(SPF_response_errcode(spf_response)));
    ret = rb_ary_new2(4);
    rb_ary_push(ret, str_result);
    rb_ary_push(ret, str_reason);
    rb_ary_push(ret, str_error);


    SPF_response_free(spf_response);
    SPF_request_free(spf_request);
    return ret;
}


static void spf2_free(void *p)
{
    SPF_server_free(p);
}

static VALUE spf2_init(VALUE self, VALUE bDebug)
{
    spf2_set_debug(self, bDebug);
    return self;
}



static VALUE spf2_alloc(VALUE klass)
{
    SPF_server_t *spf_server = NULL;
    VALUE obj;
    spf_server = SPF_server_new(SPF_DNS_CACHE, 0);
    obj = Data_Wrap_Struct(klass, 0, spf2_free, spf_server);
    return obj;

}

void Init_spf2(void)
{
    VALUE cSpf2;

    cSpf2 = rb_const_get(rb_cObject, rb_intern("Spf2"));

    rb_define_alloc_func(cSpf2, spf2_alloc);
    rb_define_method(cSpf2, "initialize", spf2_init, 1);
    rb_define_method(cSpf2, "debug=", spf2_set_debug, 1);
    rb_define_method(cSpf2, "query", spf2_query, 2);
}
