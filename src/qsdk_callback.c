/*
 * File      : qsdk_callback.c
 * This file is part of callback in qsdk
 * Copyright (c) 2018-2030, longmain Development Team
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-14     longmain     first version
 * 2018-12-13     longmain     update fun
 * 2019-06-13     longmain     add net close callback
 */

#include "qsdk.h"
#include "stdio.h"
#include "stdlib.h"

#define DBG_ENABLE
#define DBG_COLOR
#define DBG_SECTION_NAME              "[QSDK/CALLBACK]"
#ifdef QSDK_USING_LOG
#define DBG_LEVEL                      DBG_LOG
#else
#define DBG_LEVEL                      DBG_INFO
#endif /* QSDK_DEBUG */

#include <rtdbg.h>


/****************************************************
* �������ƣ� qsdk_rtc_set_time_callback
*
* �������ã� RTC���ûص�����
*
* ��ڲ����� year�����		month: �·�		day: ����
*
*							hour: Сʱ		min: ����		sec: ��		week: ����
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
void qsdk_rtc_set_time_callback(int year,char month,char day,char hour,char min,char sec,char week)
{ 
#ifdef RT_USING_RTC
	set_date(year,month,day);
	set_time(hour,min,sec);
#endif
}

/*************************************************************
*	�������ƣ�	qsdk_net_close_callback
*
*	�������ܣ�	TCP�쳣�Ͽ��ص�����
*
*	��ڲ�����	��
*
*	���ز�����	��
*
*	˵����		
*************************************************************/
void qsdk_net_close_callback(void)
{
	LOG_E("now the network is abnormally disconnected\r\n");
	
}
/****************************************************
* �������ƣ� qsdk_net_data_callback
*
* �������ã� TCP/UDP �������·����ݻص�����
*
* ��ڲ�����	data: �����׵�ַ
*
*							len: ���ݳ���
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
int qsdk_net_data_callback(char *data,int len)
{
	LOG_I("enter net callback,udp client rev data=%d,%s\r\n",len,data);
	return RT_EOK;
}

/****************************************************
* �������ƣ� qsdk_iot_data_callback
*
* �������ã� IOTƽ̨�·����ݻص�����
*
* ��ڲ����� data���·������׵�ַ
*
*							len	:	�·����ݳ���
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
int qsdk_iot_data_callback(char *data,int len)
{
	LOG_I("enter iot callback,rev data=%d,%s\r\n",len,data);
	return RT_EOK;
}	
/****************************************************
* �������ƣ� qsdk_onenet_close_callback
*
* �������ã� onenetƽ̨ǿ�ƶϿ����ӻص�����
*
* ��ڲ����� ��
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
int qsdk_onenet_close_callback()
{
	LOG_I("enter close onenent callback\r\n");

	return RT_EOK;
}
/****************************************************
* �������ƣ� qsdk_onenet_read_rsp_callback
*
* �������ã� onenetƽ̨ read�����ص�����
*
* ��ڲ����� msgid����ϢID	insid��instance id	resid: resource id
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
int qsdk_onenet_read_rsp_callback(int msgid,int insid,int resid)
{
	LOG_I("enter read dsp callback\r\n");

	return RT_EOK;
}
/****************************************************
* �������ƣ� qsdk_onenet_write_rsp_callback
*
* �������ã� onenetƽ̨ write�����ص�����
*
* ��ڲ����� len:	��Ҫд������ݳ���
*
*						 value:	��Ҫд�����������
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
int qsdk_onenet_write_rsp_callback(int len,char* value)
{
	LOG_I("enter write dsp callback\r\n");	
	return RT_EOK;
}
/****************************************************
* �������ƣ� qsdk_onenet_exec_rsp_callback
*
* �������ã� onenetƽ̨ exec�����ص�����
*
* ��ڲ����� len:	ƽ̨exec�����·����ݳ���
*
*						 cmd:	ƽ̨exec�����·���������
*
* ����ֵ�� 0 ����ɹ�	1 ����ʧ��
*****************************************************/
int qsdk_onenet_exec_rsp_callback(int len,char* cmd)
{
	LOG_I("enter exec dsp callback,exec data len:%d   data=%s\r\n",len,cmd);
	return RT_EOK;
}



/****************************************************
* �������ƣ� qsdk_onenet_fota_callback
*
* �������ã� onenet ƽ̨FOTA�����ص�����
*
* ��ڲ����� ��
*
* ����ֵ�� 	 ��
*****************************************************/
void qsdk_onenet_fota_callback(void)
{
	LOG_I("enter fota callback\r\n");
}

/****************************************************
* �������ƣ� qsdk_mqtt_data_callback
*
* �������ã� MQTT �������·����ݻص�����
*
* ��ڲ�����topic������    mesg��ƽ̨�·���Ϣ    mesg_len���·���Ϣ����
*
* ����ֵ�� 	0 ����ɹ�	1 ����ʧ��
*****************************************************/


int qsdk_mqtt_data_callback(char *topic,char *mesg,int mesg_len)
{
	LOG_I("enter mqtt callback  mesg:%s,len:%d\r\n",mesg,mesg_len);

	return RT_EOK;
}

/****************************************************
* �������ƣ� qsdk_gps_data_callback
*
* �������ã� GPS��λ�ɹ��ص�����
*
* ��ڲ�����  lon������    lat:γ��    speed���ٶ�
*
* ����ֵ�� 	0 ����ɹ�	1 ����ʧ��
*****************************************************/


int qsdk_gps_data_callback(char *lon,char *lat,float speed)
{
	LOG_I("enter gps callback  lon:%s,lat:%s,speed:%f\r\n",lon,lat,speed);

	return RT_EOK;
}
/****************************************************
* �������ƣ� qsdk_nb_reboot_callback
*
* �������ã� nb-iotģ�����⸴λ�ص�����
*
* ��ڲ�������
*
* ����ֵ��  ��
*****************************************************/
void qsdk_nb_reboot_callback(void)
{
	LOG_I("enter reboot callback\r\n");

}





