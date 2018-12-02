var context;
//alert("接收到Qt发送的消息" );
// 初始化
function init()
{
	//alert("接收到Qt发送的消息" );
    if (typeof qt != 'undefined')
    {
        new QWebChannel(qt.webChannelTransport, function(channel)
        {
        context = channel.objects.context;
        }
        //);
    }
    else
    {
        alert("qt对象获取失败！");
    }
}
// 向qt发送消息
function sendMessage(msg)
{
    if(typeof context == 'undefined')
    {
        alert("context对象获取失败！");
    }
    else
    {
        context.onMsg(msg);
    }
}
// 控件控制函数
function onBtnSendMsg()
{
    var cmd = document.getElementById("待发送消息").value;
    sendMessage(cmd);   
}
// 接收qt发送的消息
function recvMessage(msg)
{
    alert("接收到Qt发送的消息：" + msg);
}
init();
