/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: md_server.cpp
Version: 1.0
Date: 2017.4.25

History:
shengkaishan     2017.4.25   1.0     Create
******************************************************************************/

#include "md_server.h"
#include "applog.h"
#include "TapAPIError.h"
//#include "Quote.h"
#include "QuoteConfig.h"

namespace future 
{
    md_server::md_server()
    {
        //创建API实例
        string key = "md_info/authcode";
        QString authcode = common::get_config_value(key).toString();

        TAPIINT32 iResult = TAPIERROR_SUCCEED;
        TapAPIApplicationInfo stAppInfo;
        strcpy(stAppInfo.AuthCode, authcode.toStdString().c_str());
        strcpy(stAppInfo.KeyOperationLogPath, "log");
        ctpmd_api_inst = CreateTapQuoteAPI(&stAppInfo, iResult);
        ctpmd_spi_inst = new Quote();
    }
    md_server::~md_server()
    {
        ctpmd_spi_inst->m_running = false;
        if (ctpmd_api_inst) {
            //ctpmd_api_inst->SetAPINotify(nullptr);
            ctpmd_api_inst->Disconnect();
            FreeTapQuoteAPI(ctpmd_api_inst);
        }
        if (ctpmd_spi_inst->m_chk_thread != nullptr) {
            if (ctpmd_spi_inst->m_chk_thread->joinable()) {
                ctpmd_spi_inst->m_chk_thread->join();
            }
        }
        delete ctpmd_spi_inst;
        ctpmd_spi_inst = NULL;
    }

    int md_server::start_server()
    {
        TAPIINT32 iErr = TAPIERROR_SUCCEED;
        //设定服务器IP、端口
        string key = "md_info/ip";
        QString ip = common::get_config_value(key).toString();
        key = "md_info/port";
        int port = common::get_config_value(key).toInt();
        iErr = ctpmd_api_inst->SetHostAddress(ip.toStdString().c_str(), port);
        if (TAPIERROR_SUCCEED != iErr) {
            cout << "SetHostAddress Error:" << iErr << endl;
            return iErr;
        }

        ctpmd_api_inst->SetAPINotify(ctpmd_spi_inst);
        //启动测试，订阅行情
        ctpmd_spi_inst->SetAPI(ctpmd_api_inst);
        iErr = ctpmd_spi_inst->Run();
        return iErr;
    }

    void md_server::join_server()
    {
        cout << "end" << __FUNCTION__ << endl;
    }
}
