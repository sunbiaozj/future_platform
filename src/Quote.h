/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: Quote.h
Version: 1.0
Date: 2017.4.25

History:
shengkaishan     2017.4.25   1.0     Create
******************************************************************************/


#ifndef QUOTE_H
#define QUOTE_H

#include "TapQuoteAPI.h"
#include "SimpleEvent.h"
#include <map>
#include <QObject>
#include <QString>
#include <thread>
#include <memory>
#include <atomic>
using namespace std;
namespace future
{
    class Quote : public QObject, public ITapQuoteAPINotify
    {
        Q_OBJECT
    public:
        Quote(void);
        ~Quote(void);

        void SetAPI(ITapQuoteAPI* pAPI);
        int Run();

        void req_sub_market_data(string& contract);
        void req_unsub_market_data(string& contract);

    signals:
        void signals_write_log(QString str);
        void signals_quote_changed(QString last_price);
        void signals_quote_reconnect();

    private:
        void thread_reconnect();

    public:
        //对ITapQuoteAPINotify的实现
        virtual void TAP_CDECL OnRspLogin(TAPIINT32 errorCode, const TapAPIQuotLoginRspInfo *info);
        virtual void TAP_CDECL OnAPIReady();
        virtual void TAP_CDECL OnDisconnect(TAPIINT32 reasonCode);
        virtual void TAP_CDECL OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteCommodityInfo *info);
        virtual void TAP_CDECL OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteContractInfo *info);
        virtual void TAP_CDECL OnRspSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteWhole *info);
        virtual void TAP_CDECL OnRspUnSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIContract *info);
        virtual void TAP_CDECL OnRtnQuote(const TapAPIQuoteWhole *info);

    private:
        ITapQuoteAPI* m_pAPI;
        TAPIUINT32    m_uiSessionID;
        SimpleEvent m_Event;
        bool        m_bIsAPIReady;
        bool        m_bCommodity;
        bool        m_bContract;

        map<string, string> m_map_contract;

        bool        m_connect_state;
    public:
        atomic<bool> m_running;
        std::shared_ptr<std::thread> m_chk_thread;
    };
}
#endif // QUOTE_H
