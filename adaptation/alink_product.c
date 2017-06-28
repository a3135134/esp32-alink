/*
 * Copyright (c) 2014-2015 Alibaba Group. All rights reserved.
 *
 * Alibaba Group retains all right, title and interest (including all
 * intellectual property rights) in and to this computer program, which is
 * protected by applicable intellectual property laws.  Unless you have
 * obtained a separate written license from Alibaba Group., you are not
 * authorized to utilize all or a part of this computer program for any
 * purpose (including reproduction, distribution, modification, and
 * compilation into object code), and you must immediately destroy or
 * return to Alibaba Group all copies of this computer program.  If you
 * are licensed by Alibaba Group, your rights to utilize this computer
 * program are limited by the terms of that license.  To obtain a license,
 * please contact Alibaba Group.
 *
 * This computer program contains trade secrets owned by Alibaba Group.
 * and, unless unauthorized by Alibaba Group in writing, you agree to
 * maintain the confidentiality of this computer program and related
 * information and to not disclose this computer program and related
 * information to any other person or entity.
 *
 * THIS COMPUTER PROGRAM IS PROVIDED AS IS WITHOUT ANY WARRANTIES, AND
 * Alibaba Group EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED,
 * INCLUDING THE WARRANTIES OF MERCHANTIBILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE, AND NONINFRINGEMENT.
 */

#include <string.h>

#include "alink_product.h"
#include "esp_alink_log.h"

static const char *TAG = "alink_product";
static alink_product_t g_device_info;

alink_err_t product_get(_OUT_ void *product_info)
{
    ALINK_PARAM_CHECK(product_info == NULL);
    memcpy(product_info, &g_device_info, sizeof(alink_product_t));
    return ALINK_OK;
}

alink_err_t product_set(_IN_ const void *product_info)
{
    ALINK_PARAM_CHECK(product_info == NULL);
    memcpy(&g_device_info, product_info, sizeof(alink_product_t));
    return ALINK_OK;
}

char *product_get_name(char name_str[PRODUCT_NAME_LEN])
{
    return strncpy(name_str, g_device_info.name, PRODUCT_NAME_LEN);
}

char *product_get_version(char ver_str[PRODUCT_VERSION_LEN])
{
    return strncpy(ver_str, g_device_info.version, PRODUCT_VERSION_LEN);
}

char *product_get_model(char model_str[PRODUCT_MODEL_LEN])
{
    return strncpy(model_str, g_device_info.model, PRODUCT_MODEL_LEN);
}

char *product_get_key(char key_str[PRODUCT_KEY_LEN])
{
    return strncpy(key_str, g_device_info.key, PRODUCT_KEY_LEN);
}

char *product_get_secret(char secret_str[PRODUCT_SECRET_LEN])
{
    return strncpy(secret_str, g_device_info.secret, PRODUCT_SECRET_LEN);
}

char *product_get_debug_key(char key_str[PRODUCT_KEY_LEN])
{
    return strncpy(key_str, g_device_info.key_sandbox, PRODUCT_KEY_LEN);
}

char *product_get_debug_secret(char secret_str[PRODUCT_SECRET_LEN])
{
    return strncpy(secret_str, g_device_info.secret_sandbox, PRODUCT_SECRET_LEN);
}

#include "esp_wifi.h"
char *product_get_sn(char sn_str[PRODUCT_SN_LEN])
{
    uint8_t mac[6] = {0};
    ESP_ERROR_CHECK(esp_wifi_get_mac(ESP_IF_WIFI_STA, mac));
    snprintf(sn_str, PRODUCT_SN_LEN, "%02x%02x%02x%02x%02x%02x", MAC2STR(mac));
    return sn_str;
}
