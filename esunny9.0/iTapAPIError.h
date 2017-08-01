#ifndef ITAP_API_ERROR_H
#define ITAP_API_ERROR_H

//=============================================================================
/**
 *	\addtogroup G_ERR_INNER_API		TapAPI内部返回的错误码定义。
 *	@{
 */
//=============================================================================
//! 成功
namespace ITapTrade
{

    //=============================================================================
    //登录过程执行错误
	const int			TAPIERROR_LOGIN = 10001;
    //登录用户不存在
	const int			TAPIERROR_LOGIN_USER = 10002;
    //需要进行动态认证
	const int			TAPIERROR_LOGIN_DDA = 10003;
    //登录用户未授权
	const int			TAPIERROR_LOGIN_LICENSE = 10004;
    //登录模块不正确
	const int			TAPIERROR_LOGIN_MODULE = 10005;
    //需要强制修改密码
	const int			TAPIERROR_LOGIN_FORCE = 10006;
    //登录状态禁止登陆
	const int			TAPIERROR_LOGIN_STATE = 10007;
    //登录密码不正确
	const int			TAPIERROR_LOGIN_PASS = 10008;
    //没有该模块登录权限
	const int			TAPIERROR_LOGIN_RIGHT = 10009;
    //登录数量超限
	const int			TAPIERROR_LOGIN_COUNT = 10010;
    //登录用户不在服务器标识下可登录用户列表中
	const int			TAPIERROR_LOGIN_NOTIN_SERVERFLAGUSRES = 10011;
    //=============================================================================
    //数据库连接失败
	const int			TAPIERROR_CONN_DATABASE = 11000;
    //数据库操作失败
	const int			TAPIERROR_OPER_DATABASE = 11001;
    //不允许一对多
	const int			TAPIERROR_NEED_ONETOONE = 11002;
    //删除失败-存在关联信息，
	const int			TAPIERROR_EXIST_RELATEINFO = 11003;

    //登录用户密码修改失败-原始密码错误
	const int			TAPIERROR_USERPASSWORD_MOD_SOURCE = 12001;
    //登录用户密码修改失败-不能与前n次密码相同
	const int			TAPIERROR_USERPASSWORD_MOD_SAME = 12002;
    //登录用户密码修改失败-新密码不符合密码复杂度要求
	const int          TAPIERROR_USERPASSWORD_MOD_COMPLEXITY = 12003;

    //一个币种组只能设置一个基币
	const int			TAPIERROR_CURRENCY_ONLY_ONEBASE = 13001;
    //基币只能是美元或港币
	const int			TAPIERROR_CURRENCY_ONLY_USDHKD = 13002;

    //----------------交易服务错误代码定义----------------------------------------------
    //资金账号不存在
	const int			TAPIERROR_ORDERINSERT_ACCOUNT = 60001;
    //资金账号状态不正确
	const int			TAPIERROR_ORDERINSERT_ACCOUNT_STATE = 60002;

    //下单无效的合约
	const int			TAPIERROR_ORDERINSERT_CONTRACT = 60011;
    //LME未准备就绪
	const int			TAPIERROR_ORDERINSERT_LME_NOTREADY = 60012;

    //客户权限禁止交易
	const int			TAPIERROR_ORDER_NOTRADE_ACCOUNT = 60021;
    //客户品种分组禁止交易
	const int			TAPIERROR_ORDER_NOTRADE_COM_GROUP = 60022;
    //客户合约特设禁止交易
	const int			TAPIERROR_ORDER_NOTRADE_ACC_CONTRACT = 60023;
    //系统权限禁止交易
	const int			TAPIERROR_ORDER_NOTRADE_SYSTEM = 60024;
    //客户权限只可平仓
	const int			TAPIERROR_ORDER_CLOSE_ACCOUNT = 60025;
    //客户合约特设只可平仓
	const int			TAPIERROR_ORDER_CLOSE_ACC_CONTRACT = 60026;
    //系统权限只可平仓
	const int			TAPIERROR_ORDER_CLOSE_SYSTEM = 60027;


    //持仓量超过最大限制
	const int			TAPIERROR_ORDERINSERT_POSITIONMAX = 60031;
    //下单超过单笔最大量
	const int			TAPIERROR_ORDERINSERT_ONCEMAX = 60032;
    //下单合约无交易路由
	const int			TAPIERROR_ORDERINSERT_TRADEROUTE = 60033;

    //未登录网关
	const int          TAPIERROR_UPPERCHANNEL_NOT_LOGIN = 60041;

    //下单资金不足
	const int			TAPIERROR_ORDERINSERT_NOTENOUGHFUND = 60051;
    //手续费参数错误
	const int			TAPIERROR_ORDERINSERT_FEE = 60052;
    //保证金参数错误
	const int			TAPIERROR_ORDERINSERT_MARGIN = 60053;
    //总基币资金不足
	const int			TAPIERROR_ORDERINSERT_BASENOFUND = 60054;

    //撤单无此系统号
	const int          TAPIERROR_ORDERDELETE_NOT_SYSNO = 60061;
    //此状态不允许撤单
	const int          TAPIERROR_ORDERDELETE_NOT_STATE = 60062;

    //此状态不允许改单
	const int			TAPIERROR_ORDERMODIFY_NOT_STATE = 60071;
    //人工单不允许改单
	const int			TAPIERROR_ORDERMODIFY_BACK_INPUT = 60072;

    //已删除报单不能转移
	const int			TAPIERROR_ORDERINPUT_CANNOTMOVE = 60081;

    //录单重复
	const int			TAPIERROR_ORDERINPUT_REPEAT = 60091;

    //----------------网关错误代码定义-----------------------------------------------
    //网关未就绪，未连接上手
	const int			TAPIERROR_GW_NOT_READY = 80001;
    //品种错误
	const int			TAPIERROR_GW_INVALID_COMMODITY = 80002;
    //合约错误
	const int			TAPIERROR_GW_INVALID_CONTRACT = 80003;
    //报单字段有误
	const int			TAPIERROR_GW_INVALID_FIELD = 80004;
    //价格不合法
	const int		    TAPIERROR_GW_INVALID_PRICE = 80005;
    //数量不合法
	const int			TAPIERROR_GW_INVALID_VOLUME = 80006;
    //报单类型不合法
	const int			TAPIERROR_GW_INVALID_TYPE = 80007;
    //委托模式不合法
	const int			TAPIERROR_GW_INVALID_MODE = 80008;
    //委托不存在（改单、撤单）
	const int			TAPIERROR_GW_ORDER_NOT_EXIST = 80009;
    //发送报单失败
	const int			TAPIERROR_GW_SEND_FAIL = 80010;
    //被上手拒绝
	const int			TAPIERROR_GW_REJ_BYUPPER = 80011;


    //----------------交易前置错误代码定义-----------------------------------------------
    //前置不允许该模块登录
	const int			TAPIERROR_TRADEFRONT_MODULETYPEERR = 90001;
    //一次请求太多数据
	const int			TAPIERROR_TRADEFRONT_TOOMANYDATA = 90002;
    //前置没有所要数据
	const int			TAPIERROR_TRADEFRONT_NODATA = 90003;

    //前置与交易断开
	const int			TAPIERROR_TRADEFRONT_DISCONNECT_TRADE = 90011;
    //前置与管理断开
	const int			TAPIERROR_TRADEFRONT_DISCONNECT_MANAGE = 90012;

    //下属资金账号不存在
	const int			TAPIERROR_TRADEFRONT_ACCOUNT = 90021;
    
    
    
    const int TAPIERROR_SUCCEED                                            = 0;
    //! 连接服务失败
    const int TAPIERROR_ConnectFail                                        = -1;
    //! 链路认证失败
    const int TAPIERROR_LinkAuthFail                                       = -2;
    //! 主机地址不可用
    const int TAPIERROR_HostUnavailable                                    = -3;
    //! 发送数据错误
    const int TAPIERROR_SendDataError                                      = -4;
    //! 测试编号不合法
    const int TAPIERROR_TestIDError                                        = -5;
    //! 没准备好测试网络
    const int TAPIERROR_NotReadyTestNetwork                                = -6;
    //! 当前网络测试还没结束
    const int TAPIERROR_CurTestNotOver                                     = -7;
    //! 没用可用的接入前置
    const int TAPIERROR_NOFrontAvailable                                   = -8;
    //! 数据路径不可用
    const int TAPIERROR_DataPathAvaiable                                   = -9;
    //! 重复登录
    const int TAPIERROR_RepeatLogin                                        = -10;
    //! 内部错误	
    const int TAPIERROR_InnerError                                         = -11;
    //! 上一次请求还没有结束	
    const int TAPIERROR_LastReqNotFinish                                   = -12;
    //! 输入参数非法	
    const int TAPIERROR_InputValueError                                    = -13;
    //! 授权码不合法	
    const int TAPIERROR_AuthCode_Invalid                                   = -14;
    //! 授权码超期	
    const int TAPIERROR_AuthCode_Expired                                   = -15;
    //! 授权码类型不匹配	
    const int TAPIERROR_AuthCode_TypeNotMatch                              = -16;
    //! API还没有准备好
    const int TAPIERROR_API_NotReady                                       = -17;
    //! UDP端口监听失败
    const int TAPIERROR_UDP_LISTEN_FAILED                                  = -18;
    //! UDP正在监听
    const int TAPIERROR_UDP_LISTENING                                      = -19;
    //! 接口未实现
    const int TAPIERROR_NotImplemented                                     = -20;
    //! 每次登陆只允许调用一次
    const int TAPIERROR_CallOneTimeOnly                                    = -21;
	//超过下单频率。
	const int TAPIERROR_ORDER_FREQUENCY										= -22;
	//查询频率太快。
	const int TAPIERROR_RENTQRY_TOOFAST										= -23;

    /** @}*/


    //=============================================================================
    /**
     *	\addtogroup G_ERR_INPUT_CHECK		输入参数检查错误
     *	@{
     */
    //=============================================================================
    //! 输入数据为NULL
    const int TAPIERROR_INPUTERROR_NULL                                    = -10000;
    //! 输入错误的:TAPIYNFLAG
    const int TAPIERROR_INPUTERROR_TAPIYNFLAG                              = -10001;
    //! 输入错误的:TAPILOGLEVEL
    const int TAPIERROR_INPUTERROR_TAPILOGLEVEL                            = -10002;
    //! 输入错误的:TAPICommodityType
    const int TAPIERROR_INPUTERROR_TAPICommodityType                       = -10003;
    //! 输入错误的:TAPICallOrPutFlagType
    const int TAPIERROR_INPUTERROR_TAPICallOrPutFlagType                   = -10004;
    //! 输入错误的:TAPIBucketDateFlag
    const int TAPIERROR_INPUTERROR_TAPIBucketDateFlag                      = -11001;
    //! 输入错误的:TAPIHisQuoteType
    const int TAPIERROR_INPUTERROR_TAPIHisQuoteType                        = -11002;
    //! 输入错误的:TAPIAccountType
    const int TAPIERROR_INPUTERROR_TAPIAccountType                         = -12001;
    //! 输入错误的:TAPIUserTypeType
    const int TAPIERROR_INPUTERROR_TAPIUserTypeType                        = -12002;
    //! 输入错误的:TAPIAccountState
    const int TAPIERROR_INPUTERROR_TAPIAccountState                        = -12003;
    //! 输入错误的:TAPIAccountFamilyType
    const int TAPIERROR_INPUTERROR_TAPIAccountFamilyType                   = -12004;
    //! 输入错误的:TAPIOrderTypeType
    const int TAPIERROR_INPUTERROR_TAPIOrderTypeType                       = -12005;
    //! 输入错误的:TAPIOrderSourceType
    const int TAPIERROR_INPUTERROR_TAPIOrderSourceType                     = -12006;
    //! 输入错误的:TAPITimeInForceType
    const int TAPIERROR_INPUTERROR_TAPITimeInForceType                     = -12007;
    //! 输入错误的:TAPISideType
    const int TAPIERROR_INPUTERROR_TAPISideType                            = -12008;
    //! 输入错误的:TAPIPositionEffectType
    const int TAPIERROR_INPUTERROR_TAPIPositionEffectType                  = -12009;
    //! 输入错误的:TAPIHedgeFlagType
    const int TAPIERROR_INPUTERROR_TAPIHedgeFlagType                       = -12010;
    //! 输入错误的:TAPIOrderStateType
    const int TAPIERROR_INPUTERROR_TAPIOrderStateType                      = -12011;
    //! 输入错误的:TAPICalculateModeType
    const int TAPIERROR_INPUTERROR_TAPICalculateModeType                   = -12012;
    //! 输入错误的:TAPIMatchSourceType
    const int TAPIERROR_INPUTERROR_TAPIMatchSourceType                     = -12013;
    //! 输入错误的:TAPIOpenCloseModeType
    const int TAPIERROR_INPUTERROR_TAPIOpenCloseModeType                   = -12014;
    //! 输入错误的:TAPIFutureAlgType
    const int TAPIERROR_INPUTERROR_TAPIFutureAlgType                       = -12015;
    //! 输入错误的:TAPIOptionAlgType
    const int TAPIERROR_INPUTERROR_TAPIOptionAlgType                       = -12016;
    //! 输入错误的:TAPIBankAccountLWFlagType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountLWFlagType               = -12017;
    //! 输入错误的:TAPIBankAccountStateType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountStateType                = -12018;
    //! 输入错误的:TAPIBankAccountSwapStateType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountSwapStateType            = -12019;
    //! 输入错误的:TAPIBankAccountTransferStateType
    const int TAPIERROR_INPUTERROR_TAPIBankAccountTransferStateType        = -12020;
    //! 输入错误的:TAPIMarginCalculateModeType
    const int TAPIERROR_INPUTERROR_TAPIMarginCalculateModeType             = -12021;
    //! 输入错误的:TAPIOptionMarginCalculateModeType
    const int TAPIERROR_INPUTERROR_TAPIOptionMarginCalculateModeType       = -12022;
    //! 输入错误的:TAPICmbDirectType
    const int TAPIERROR_INPUTERROR_TAPICmbDirectType                       = -12023;
    //! 输入错误的:TAPIDeliveryModeType
    const int TAPIERROR_INPUTERROR_TAPIDeliveryModeType                    = -12024;
    //! 输入错误的:TAPIContractTypeType
    const int TAPIERROR_INPUTERROR_TAPIContractTypeType                    = -12025;
    //! 输入错误的:TAPIPartyTypeType
    const int TAPIERROR_INPUTERROR_TAPIPartyTypeType                       = -12026;
    //! 输入错误的:TAPIPartyCertificateTypeType
    const int TAPIERROR_INPUTERROR_TAPIPartyCertificateTypeType            = -12027;
    //! 输入错误的:TAPIMsgReceiverType
    const int TAPIERROR_INPUTERROR_TAPIMsgReceiverType                     = -12028;
    //! 输入错误的:TAPIMsgTypeType
    const int TAPIERROR_INPUTERROR_TAPIMsgTypeType                         = -12029;
    //! 输入错误的:TAPIMsgLevelType
    const int TAPIERROR_INPUTERROR_TAPIMsgLevelType                        = -12030;
    //! 输入错误的:TAPITransferDirectType
    const int TAPIERROR_INPUTERROR_TAPITransferDirectType                  = -12031;
    //! 输入错误的:TAPITransferStateType
    const int TAPIERROR_INPUTERROR_TAPITransferStateType                   = -12032;
    //! 输入错误的:TAPITransferTypeType
    const int TAPIERROR_INPUTERROR_TAPITransferTypeType                    = -12033;
    //! 输入错误的:TAPITransferDeviceIDType
    const int TAPIERROR_INPUTERROR_TAPITransferDeviceIDType                = -12034;
    //! 输入错误的:TAPITacticsTypeType
    const int TAPIERROR_INPUTERROR_TAPITacticsTypeType                     = -12035;
    //! 输入错误的:TAPIORDERACT
    const int TAPIERROR_INPUTERROR_TAPIORDERACT                            = -12036;
    //! 输入错误的:TAPIBillTypeType
    const int TAPIERROR_INPUTERROR_TAPIBillTypeType                        = -12037;
    //! 输入错误的:TAPIBillFileTypeType
    const int TAPIERROR_INPUTERROR_TAPIBillFileTypeType                    = -12038;
    //! 输入错误的:TAPIOFFFlagType
    const int TAPIERROR_INPUTERROR_TAPIOFFFlagType                         = -12039;
    //! 输入错误的:TAPICashAdjustTypeType
    const int TAPIERROR_INPUTERROR_TAPICashAdjustTypeType                  = -12040;
    //! 输入错误的:TAPITriggerConditionType
    const int TAPIERROR_INPUTERROR_TAPITriggerConditionType                = -12041;
    //! 输入错误的:TAPITriggerPriceTypeType
    const int TAPIERROR_INPUTERROR_TAPITriggerPriceTypeType                = -12042;
    //! 输入错误的:TAPITradingStateType 
    const int TAPIERROR_INPUTERROR_TAPITradingStateType                    = -12043;
    //! 输入错误的:TAPIMarketLevelType 
    const int TAPIERROR_INPUTERROR_TAPIMarketLevelType                     = -12044;
    //! 输入错误的:TAPIOrderQryTypeType 
    const int TAPIERROR_INPUTERROR_TAPIOrderQryTypeType                    = -12045;

    //! 历史行情查询参数不合法
    const int TAPIERROR_INPUTERROR_QryHisQuoteParam                        = -13001;

    /** @}*/

    //=============================================================================
    /**
     *	\addtogroup G_ERR_DISCONNECT_REASON	网络断开错误代码定义
     *	@{
     */
    //=============================================================================
    //! 主动断开
    const int TAPIERROR_DISCONNECT_CLOSE_INIT                              = 1;
    //! 被动断开
    const int TAPIERROR_DISCONNECT_CLOSE_PASS                              = 2;
    //! 读错误
    const int TAPIERROR_DISCONNECT_READ_ERROR                              = 3;
    //! 写错误
    const int TAPIERROR_DISCONNECT_WRITE_ERROR                             = 4;
    //! 缓冲区满
    const int TAPIERROR_DISCONNECT_BUF_FULL                                = 5;
    //! 异步操作错误
    const int TAPIERROR_DISCONNECT_IOCP_ERROR                              = 6;
    //! 解析数据错误
    const int TAPIERROR_DISCONNECT_PARSE_ERROR                             = 7;
    //! 连接超时
    const int TAPIERROR_DISCONNECT_CONNECT_TIMEOUT                         = 8;
    //! 初始化失败
    const int TAPIERROR_DISCONNECT_INIT_ERROR                              = 9;
    //! 已经连接
    const int TAPIERROR_DISCONNECT_HAS_CONNECTED                           = 10;
    //! 工作线程已结束
    const int TAPIERROR_DISCONNECT_HAS_EXIT                                = 11;
    //! 操作正在进行，请稍后重试
    const int TAPIERROR_DISCONNECT_TRY_LATER                               = 12;

    /** @}*/
}
#endif //! TAP_API_ERROR_H
