
#include"all.h"//包含所以头文件


int MyR[10] = { 1 ,0,0,0,0,0,0,0,0,0 }, MyG[10] = { 1,0,0,0,0,0,0,0,0,0 }, MyB[10] = { 0 ,0,0,0,0,0,0,0,0,0 };//自定义颜色数组
int main()
{
	{
		
		initgraph(WIDTH, HIGHT);//定义画布
	setbkcolor(WHITE);//设置背景颜色
	cleardevice();//
	uishow();//一些图像界面绘制
	xylocation();//显示xy坐标
	loadimage(&pic[0], _T(".\\images\\1 (1).png"));
	loadimage(&pic[1], _T(".\\images\\1 (2).png"));
	loadimage(&pic[2], _T(".\\images\\1 (3).png"));
	loadimage(&pic[3], _T(".\\images\\1 (4).png"));//加载功能图标
	loadimage(&picpen, _T(".\\无标题.png"));//加载笔样式图标
	loadimage(&form, _T(".\\images\\1.png"));//加载图形图标
	loadimage(&colorline, _T(".\\images\\色条.png"));//加载固定色条
	loadimage(&mycolorline, _T(".\\images\\自定义色条.png"));//加载自定义色标底板
	loadimage(&savep, _T(".\\保存.png"));//加载保存按键图标
	loadimage(&explainp, _T(".\\说明.png"));//加载说明按键图标
	loadimage(&exitp, _T(".\\退出.png"));//加载退出按键图标
	loadimage(&explanishow, _T(".\\说明界面.png"));
	putimage(230, 5, &picpen);
	putimage(420, 40, &form);
	putimage(750, 14, &colorline);
	putimage(750, 44, &mycolorline);
	putimage(420, 0, &savep);

	
	putimage(460, 0, &explainp);//放置一些基础图片
	BeginBatchDraw();//开始批量绘图
	load();//加载自定义颜色
	//save();//保存自定义颜色
	}//预加载
	while (1)//循环
	{
		openimg();//打开图片
		setrop2(R2_COPYPEN);//颜色模式为当前颜色
		avoidbug();//防止弹出继续画图，防bug
		MouseChange();//获取当前鼠标位置
		menu();//菜单功能选择
		formchose();//作图形式选择
		avoidbug();//防止弹出继续画图
		linethickness();//线条粗细选择
		setlinestyle(0);//恢复线条为实线
		Resetlinestyle();//设置线条样式
		resetr();//设置角度
		ResetColor();//设置颜色
		SetColor();//选择设置已有颜色
		SetMyColor();//选择自定义颜色
		uishow();//一些图像界面绘制
		MouseChange();//获取当前鼠标位置
		explan();//说明
		saveimage();//保存图片
		EndBatchDraw();//结束批量绘图
		
	}
	_getch();//防退
	closegraph();//关闭画布
}
void menu() //主要功能
{
	setlinecolor(BLACK);//颜色黑色
	setlinestyle(PS_SOLID, 1);//1宽度实现
	roundrect(225, 6 + 12 * penstyle, 295, 15 + 12 * penstyle, 2, 2);//当前画笔样式选择框
	peekmessage(&mouse, EM_MOUSE);//获取鼠标信息
	if (mouse.x >= 0 && mouse.x <= 960 && mouse.y >= 80+linethick/2 && mouse.y <= 640)//鼠标位于作图区
	{
		setlinestyle(penstyle);//设置画笔样式
		if (functionnum == 0)//功能：画笔自由作画
			Freedrawing();
		if (functionnum == 1)//功能：填充区域
			Fill();
		if (functionnum == 2)//功能：橡皮檫
			clean();
		if (functionnum == 3)
			getColor();

			xylocation();//显示xy坐标位置
	}
	allclean();//全部清除函数
	
}
void avoidbug()//防止弹出继续画图
{
	if (mouse.lbutton != 1|| mouse.message == WM_LBUTTONUP)
		isdown = 0;//鼠标未按下
}
void MouseChange()//不断获取前一个mouse的xy
{
	if (mouse.x >= 0 && mouse.x <= 960 && mouse.y >= 80 && mouse.y <= 640)//鼠标位于作图区
	{
		mousex = mouse.x;
		mousey = mouse.y;
	}
	else//在功能区获得的是功能区的前一个mouse的xy
	{
		emousex = mouse.x;
		emousey = mouse.y;
	}
}
void Resetlinestyle()//设置线条样式
{
   
	for (int i = 0;i <= 4;i++)
		if (mouse.x >= 225 && mouse.x < 295 && mouse.y >= 6 + 12 * i && mouse.y <= 15 + 12 * i)
	    {
			if (mouse.message == WM_LBUTTONDOWN)
			{
				if (penstyle != i)
				{
					setlinecolor(WHITE);
					setlinestyle(PS_SOLID, 1);
					roundrect(225, 6 + 12 * penstyle, 295, 15 + 12 * penstyle, 2, 2);
				}
				penstyle = i;
				setlinecolor(BLACK);
				setlinestyle(PS_SOLID, 1);
				roundrect(225, 6 + 12 * penstyle, 295, 15 + 12 * penstyle, 2, 2);
				
			}
		}
	
	
}
void uishow()//界面展示
{
	setlinecolor(BLACK);
	line(0, 80, 960, 80);//分割线，将画布分为功能区和绘图区
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	roundrect(420, 65, 540, 70, 1, 1);
	roundrect(310, 4, 320, 69, 2, 2);
	roundrect(600, 20, 700, 30, 2, 2);//RGB颜色框打印的边框
	_stprintf(s, _T("θ:%.2lf"), r2);//弧度显示
	outtextxy(550, 63, s);//弧度显示
	_stprintf(s, _T("%02d"), linethick);//线条粗细显示
	outtextxy(335, 63, s);//线条粗细显示
	_stprintf(s, _T("R:%03d"), x);
	outtextxy(703, 17, s);
	roundrect(600, 35, 700, 45, 2, 2);
	_stprintf(s, _T("G:%03d"), y);
	outtextxy(703, 32, s);
	roundrect(600, 50, 700, 60, 2, 2);
	_stprintf(s, _T("B:%03d"), z);
	outtextxy(703, 47, s);//RGB显示
	outtextxy(2, 5, L"NOW COLOR");//打印字样NOW COLOR
	for (int i = 0;i <= 3;i++)
	{
		putimage(90 + i * 32, 25, &pic[i]);//依次打印功能图片
		if (mouse.x >= 90 + i * 32 && mouse.x < 120 + i * 32 && mouse.y >= 25 && mouse.y <= 53)
			if (mouse.message == WM_LBUTTONDOWN)
			{
				setlinecolor(WHITE);
				roundrect(89 + functionnum * 32, 24, 121 + functionnum * 32, 54, 4, 4);//覆盖待选功能
				functionnum = i;
				roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);//覆盖图形类别确定的功能
				formsure = -100;//图形类别确定-100
			}
	}
	setlinecolor(BLACK);
	roundrect(89 + functionnum * 32, 24, 121 + functionnum * 32, 54, 4, 4);//待选功能框
}
void getColor()//获取当前颜色
{
	if (mouse.message == WM_LBUTTONDOWN)
	{
		x = GetRValue(getpixel(mouse.x, mouse.y));
		y = GetGValue(getpixel(mouse.x, mouse.y));
		z = GetBValue(getpixel(mouse.x, mouse.y));//使用获取RGB颜色的函数
	}
	
}
void Freedrawing()//自由画画函数
{
	
	if (mouse.message == WM_LBUTTONDOWN)//按下鼠标左键
	{
		BeginBatchDraw();//批量绘制开始
		mousex = mouse.x;
		mousey = mouse.y;
		isdown = 1;
	}
	if (mouse.message == WM_LBUTTONUP)//弹起鼠标左键
	{
		FlushBatchDraw();//批量绘制结束
		isdown = 0;
	}
	if (isdown == 1 && mouse.message == WM_MOUSEMOVE)//按键按下并且移动
	{
		setlinecolor(RGB(x, y, z));//设置为当前颜色
		setlinestyle(penstyle,linethick);//设置画笔为当前粗细和样式
		line(mousex, mousey, mouse.x, mouse.y);//通过不断获取前一个鼠标位置使用线条来实现自由绘画
	}

}
void Fill()//颜色填充
{
	if (mouse.message == WM_LBUTTONDOWN)//按下鼠标左键
	{
		setfillcolor(RGB(x, y, z));//设置为当前颜色
		setfillstyle(BS_SOLID);//填充类型为紧密实现
		mousex = mouse.x;
		mousey = mouse.y;
		floodfill(mousex, mousey, getpixel(mousex, mousey), 1);//使用flooffill函数，再用getpixel识别颜色，后面参数为1，则执行为使识别到的颜色在边界内变为你设值的颜色
	}
}
void SetColor()//选择设置已有颜色 -----方式与fromsure函数一致
{
	
	if (mouse.x >= 750  && mouse.x <= 770 + 20 * 8 && mouse.y >= 14 && mouse.y <= 34)
	{
		peekmessage(&mouse, EM_MOUSE);
		for (int i = 0;i <= 8;i++)
			if (mouse.x >= 750 + 23 * i && mouse.x < 770 + 23 * i && mouse.y >= 14 && mouse.y <= 34)
			{
				setlinecolor(BLACK);
				rectangle(749 + 23 * colorsure, 13, 770 + 23 * colorsure, 34);
				if (i != colornum)
				{
					setlinecolor(WHITE);
					rectangle(749 + 23 * colornum, 13, 770 + 23 * colornum, 34);
				}
				colornum = i;
				setlinecolor(BLACK);
				rectangle(749 + 23 * colornum, 13, 770 + 23 * colornum, 34);
				if (mouse.message == WM_LBUTTONDOWN)
				{
					setlinecolor(WHITE);
					rectangle(749 + 23 * colorsure, 13, 770 + 23 * colorsure, 34);
					rectangle(749 + 23 * mycolorsure, 43, 770 + 23 * mycolorsure, 64);
					mycolorsure = -100;
					colorsure = i;
				}
			}
		
	}
	else
	{
		setlinecolor(WHITE);
		rectangle(749 + 23 * colornum, 13, 770 + 23 * colornum, 34);
		setlinecolor(BLACK);
		rectangle(749 + 23 * colorsure, 13, 770 + 23 * colorsure, 34);
	}
	if (colorsure >= 0) {

	
	switch (colorsure)
	{
	case 0:x = y = z = 255;break;
	case 1:x = y = z = 0;break;
	case 2:x = 255;y = 0;z = 0;break;
	case 3:x = y = 255;z = 0;break;
	case 4:x = z = 0;y = 255;break;
	case 5:x = y = 0;z = 255;break;
	case 6:x = 0;y = z = 255;break;
	case 7:y = 0;x = z = 255;break;//将RGB条改为选择的颜色
	}
	setfillcolor(WHITE);
	solidroundrect(600, 21, 700, 29, 2, 2);
	solidroundrect(601, 36,700, 44, 2, 2);
	solidroundrect(600, 51, 700, 59, 2, 2);
	setfillcolor(RGB(x, 0, 0));
	solidroundrect(600, 21,600+100*x/255, 29, 2, 2);
	setfillcolor(RGB(0, y, 0));
	solidroundrect(601, 36, 600+ 100 * y/ 255,44 ,2, 2);
	setfillcolor(RGB(0, 0, z));
	solidroundrect(600, 51, 600+ 100*z/255,59, 2, 2);}//将RGB条改为选择的颜色
}
void SetMyColor()//选择设置自己保存的颜色 -----方式与fromsure函数一致
{

	if (mouse.x >= 750 && mouse.x <= 770 + 20 * 8 && mouse.y >= 44 && mouse.y <= 64)
	{
		peekmessage(&mouse, EM_MOUSE);
		for (int i = 0;i < 8;i++)
			if (mouse.x >= 750 + 23 * i && mouse.x < 770 + 23 * i && mouse.y >= 44 && mouse.y <= 64)
			{
				setlinecolor(BLACK);
				rectangle(749 + 23 * mycolorsure, 43, 770 + 23 * mycolorsure, 64);
				if (i != mycolornum)
				{
					setlinecolor(WHITE);
					rectangle(749 + 23 * mycolornum, 43, 770 + 23 * mycolornum, 64);
				}
				mycolornum = i;
				setlinecolor(BLACK);
				rectangle(749 + 23 * mycolornum, 43, 770 + 23 * mycolornum, 64);
				if (mouse.message == WM_LBUTTONDOWN)
				{
					setlinecolor(WHITE);
					if (i == mycolorsure)
						rectangle(749 + 23 * mycolorsure, 43, 770 + 23 * mycolorsure, 64);
					rectangle(749 + 23 * mycolorsure, 43, 770 + 23 * mycolorsure, 64);
					rectangle(749 + 23 * colorsure, 13, 770 + 23 * colorsure, 34);
					colorsure = -100;
					mycolorsure = i;
				}
			}

	}
	else
	{
		setlinecolor(WHITE);
		rectangle(749 + 23 * mycolornum, 43, 770 + 23 * mycolornum, 64);//覆盖待选择颜色
		setlinecolor(BLACK);
		rectangle(749 + 23 * mycolorsure, 43, 770 + 23 * mycolorsure, 64);//打印当前选择颜色边框
	}
	if (mycolorsure >= 0)//确定自定义颜色
	{
		cc1++;
		if (cc1 == 100)
		{

			cc1 = 0;
			load();
			x = MyR[mycolorsure + 1];
			y = MyG[mycolorsure + 1];
			z = MyB[mycolorsure + 1];//获取颜色
		}
		setfillcolor(WHITE);
		solidroundrect(600, 21, 700, 29, 2, 2);
		solidroundrect(601, 36, 700, 44, 2, 2);
		solidroundrect(600, 51, 700, 59, 2, 2);
		setfillcolor(RGB(x, 0, 0));
		solidroundrect(600, 21, 600 + 100 * x / 255, 29, 2, 2);
		setfillcolor(RGB(0, y, 0));
		solidroundrect(601, 36, 600 + 100 * y / 255, 44, 2, 2);
		setfillcolor(RGB(0, 0, z));
		solidroundrect(600, 51, 600 + 100 * z / 255, 59, 2, 2);//将RGB条改为选择的颜色
	}
	
}
void ResetColor()//自行设置颜色
{
	setfillcolor(WHITE);
	if (mouse.x >= 600 && mouse.x <= 700 && mouse.y >= 20 && mouse.y <= 30 && mouse.lbutton == 1)
	{
		ResetColorRed();
		
		colorsure = -100;//颜色选择-100
		//mycolorsure = -100;
	}
	if (mouse.x >= 600 && mouse.x <= 700 && mouse.y >= 35 && mouse.y <= 45 && mouse.lbutton == 1)
	{
		ResetColorGreen();
		
		colorsure = -100;//颜色选择-100
		//mycolorsure = -100;
	}
	if (mouse.x >= 600 && mouse.x <= 700 && mouse.y >= 50 && mouse.y <= 60 && mouse.lbutton == 1)
	{
		ResetColorBlue();
		//mycolorsure = -100;
		colorsure = -100;//颜色选择-100
	}
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	setfillcolor(RGB(x, y, z));
	fillrectangle(23, 23, 53, 53);
	if (mycolorsure >= 0)
	{
		int c = mycolorsure + 1;
		cc++;
		if(cc==100)
		{
			cc = 0;
			MyR[c] = (int)x;
			MyG[c] = (int)y;
			MyB[c] = (int)z;//获取颜色值
			save();
			setlinecolor(0xB7B7B7);
			setfillcolor(RGB(MyR[c], MyG[c], MyB[c]));
			fillrectangle(750 + 23 * (mycolorsure), 44, 769 + 23 * (mycolorsure), 63);//自定义颜色选择;
		}
		
	}
}
void ResetColorRed()//设置R
{
	if (mouse.message == WM_LBUTTONDOWN)
	{
		emousex = mouse.x;
		emousey = mouse.y;
		solidroundrect(600, 21, 700, 29, 2, 2);
		isdown = 6;
	}
	if (mouse.message == WM_LBUTTONUP)
	{
		isdown = 0;
	}
	if (isdown == 6 && mouse.message == WM_MOUSEMOVE)
	{
		{
			if (emousex > mouse.x&&emousex<=700&&emousex>=600)//鼠标向左
				solidroundrect(emousex, 21, 700, 29,2,2);
			setfillcolor(RGB(x,0,0));
			solidroundrect(600, 21, mouse.x, 29,2,2);
		}
		x = 255 * (mouse.x - 600) / 100;
	}
}
void xylocation()//显示xy坐标
{
	setbkmode(OPAQUE);
	settextcolor(BLACK);
	_stprintf(s, _T("X:%03d  Y:%03d"), mouse.x,mouse.y-80);
	outtextxy(5, 60,s);//XY的坐标
	_stprintf(s, _T("BX:%03d  BY:%03d"), bmousex, bmousey - 80);
	outtextxy(120, 60, s);//开始XY坐标
	clearrectangle(90, 10, 210, 25);
	_stprintf(s, _T("CX:%03d"), mouse.x-bmousex);
	outtextxy(100, 10, s);//x的差值
	_stprintf(s, _T("CY:%03d"),mouse.y - 80 - (bmousey - 80));
	outtextxy(160, 10, s);//y的差值
}
void ResetColorGreen()//设置G
{
	if (mouse.message == WM_LBUTTONDOWN)
	{
		emousex = mouse.x;
		emousey = mouse.y;
		solidroundrect(600, 36, 700, 44, 2, 2);
		isdown = 5;
	}
	if (mouse.message == WM_LBUTTONUP)
	{
		isdown = 0;
	}
	if (isdown == 5 && mouse.message == WM_MOUSEMOVE)
	{
		{
			if (emousex > mouse.x && emousex <= 700 && emousex >= 600)//鼠标向左
				solidroundrect(emousex, 36, 700, 44,2,2);
			setfillcolor(RGB(0,y,0));
			solidroundrect(601, 36, mouse.x, 44,2,2);
		}
		y = 255 * (mouse.x - 600) / 100;
	}
}
void ResetColorBlue()//设置B
{
	if (mouse.message == WM_LBUTTONDOWN)
	{
		emousex = mouse.x;
		emousey = mouse.y;
		solidroundrect(600, 51, 700, 59, 2, 2);
		isdown = 4;
	}
	if (mouse.message == WM_LBUTTONUP)
	{
		isdown = 0;
	}
	if (isdown == 4 && mouse.message == WM_MOUSEMOVE)
	{
		{
			if (emousex > mouse.x && emousex <= 700 && emousex >= 600)//鼠标向左
				solidroundrect(emousex, 51, 700, 59,2,2);
			setfillcolor(RGB(0,0,z));
			solidroundrect(600, 51, mouse.x, 59,2,2);
		}
		z= 255 * (mouse.x - 600) / 100;
	}
}
void linethickness()//线条粗细设置
{
	setfillcolor(BLACK);
	solidcircle(365, 35, linethick);
	if (mouse.x >= 310 && mouse.x <= 320 && mouse.y >= 4 && mouse.y <= 69) {
		if (mouse.message == WM_LBUTTONDOWN)
		{
			emousex = mouse.x;
			emousey = mouse.y;
			isdown = 2;
			
		}
		if (mouse.message == WM_LBUTTONUP)
		{
			isdown = 0;
		}
		if (isdown == 2 && mouse.message == WM_MOUSEMOVE)
		{
			{
				setfillcolor(BLACK);
				if (emousey > mouse.y && emousey >= 4 && emousey <= 69)
					solidroundrect(311, emousey, 319, 68, 2, 2);
				setfillcolor(WHITE);
				solidroundrect(311, 4, 319, mouse.y, 2, 2);
			}
			if(linethick>30*(70-mouse.y)/69+1)
				clearcircle(365, 35, linethick);
			linethick =30*(70 - mouse.y)/69+1 ;//求出线条粗细
			setfillcolor(BLACK);
			solidcircle(365, 35, linethick);//通过圆来反应
		}
	}
}
void clean()//橡皮檫（实际上为白色画笔）
{
	setlinecolor(WHITE);
	setlinestyle(0, linethick);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		mousex = mouse.x;
		mousey = mouse.y;
		isdown = 3;
	}
	if (mouse.message == WM_LBUTTONUP)
	{
		isdown = 0;
	}
	if (isdown == 3&& mouse.message == WM_MOUSEMOVE)
	{
		line(mousex, mousey, mouse.x, mouse.y);
	}
}
void allclean()//清空画布
{
	if (mouse.x >= 90 + 2 * 32 && mouse.x < 120 + 2 * 32 && mouse.y >= 25 && mouse.y <= 53 && mouse.lbutton == 1)//在橡皮檫图片上
		count++;//一直点击，次数增加
	else
		count = 0;//未在区域清空为0
	if (count >= 3000)//充当时间计次，超过就弹出提示框
	{
		//MessageBox(NULL, _T("是否全部清除？"), _T("提示"), MB_OKCANCEL|MB_ICONQUESTION|MB_SYSTEMMODAL);
		if (MessageBox(NULL, _T("是否全部清除？"), _T("提示"), MB_OKCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL) == IDOK)//如果选择的是确定，进行清除
			clearrectangle(0, 81, 960, 640);//清除绘图区
		count = 0;
	}
}
void formchose()//用于图形绘制的选择
{
	if (mouse.x >= 420 && mouse.x <= 540 && mouse.y >= 40 && mouse.y <= 60) //在图形选择区域
	{
		setlinestyle(PS_SOLID, 1);//设置为1宽度的实线
		for (int i = 0;i <= 5;i++)//共有五个图形类别
			if (mouse.x >= 420 + i * 20 && mouse.x < 440 + i * 20 && mouse.y >= 40 && mouse.y <= 60)//在哪个图形类别上
			{
				peekmessage(&mouse, EM_MOUSE);
				if (i != formnum)//如果当前不是同一个鼠标待选类别
				{
					setlinecolor(WHITE);
					roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//清空前一个
				}
				formnum = i;//确定鼠标待选图形类别
				if (mouse.message == WM_LBUTTONDOWN)//鼠标左键点击
				{
					
					setlinecolor(WHITE);
					roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);
					formsure = i;//设置当前确定的图形类别
				}
				setlinecolor(0x7F7F7F);//设置颜色为灰色
				roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//绘制出当前待选图形类别
				setlinecolor(BLACK);//设置为黑色
				roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);//绘制出当前确定的图形类别
			}
	}
	else
	{
		setlinestyle(PS_SOLID, 1);//设置为1宽度的实线
		setlinecolor(WHITE);//设置颜色白色
		roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//覆盖待选图片类别
		formnum = -100;//待选数-100
		setlinecolor(BLACK);//设置颜色黑色
		roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);//绘制出当前确定的图形类别
	}
	if (formsure>=0)//如果以及有选择的图形类别
	{
		setlinecolor(WHITE);//颜色白色
		setlinestyle(PS_SOLID, 1);//设置为1宽度的实线
		roundrect(89 + functionnum * 32, 24, 121 + functionnum * 32, 54, 4, 4);//功能的选择清空
		functionnum = -100;//功能选择数-100

	}
	if (mouse.x >= 0 && mouse.x <= 960 && mouse.y >= 80 && mouse.y <= 640)//鼠标位于作图区
	{
		setlinecolor(WHITE);//颜色白色
		roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//覆盖待选图片类别
		formnum = -100;//待选数-100
		if (formsure == 0)//图形类别0
		    drawline();//画直线
		if (formsure == 1)//图形类别1
			draws();//画圆弧
		if (formsure == 2)//图形类别2
			drawsector();//画扇形
		if (formsure == 3)//图形类别3
			drawcircle();//画圆
		if (formsure == 4)//图形类别4
			drawellipse();//画椭圆
		if (formsure == 5)//图形类别5
			drawbox();//画矩形
		

	}
}
void drawline()//画直线
{
	mouse = getmessage(EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//开始点的位置坐标
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);
		while (1)
		{
			BeginBatchDraw();
			xylocation();//采集鼠标位置等
			mouse = getmessage(EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //在作图区执行
			{


				if (mouse.lbutton == 1)
				{
					if (mouse.x < WIDTH && mouse.y > 80)
					{
						if (mouse.message == WM_MOUSEMOVE) {
							if (bmousex != 0 && mousey != 0)//防止从原点开始画
								line(bmousex, bmousey, mousex, mousey);//直线绘制
							mousex = mouse.x; mousey = mouse.y;
							if (bmousex != 0 && mousey != 0)//防止从原点开始画
								line(bmousex, bmousey, mousex, mousey);
						}

					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//右键取消当前绘制，将图形覆盖
				{

					line(bmousex, bmousey, mouse.x, mouse.y);
					line(bmousex, bmousey, bmousex, bmousey);
					mousex = mouse.x; mousey = mouse.y;
					break;
				}
				if (mouse.message == WM_LBUTTONUP)
				{
					setlinecolor(RGB(x, y, z));
					setrop2(R2_COPYPEN);
					if (bmousex != 0 && mousey != 0)//防止从原点开始画
						line(bmousex, bmousey, mouse.x, mouse.y);

					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void drawbox()//矩形绘制
{
	mouse = getmessage(EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//开始点的位置坐标
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);
		while (1)
		{
			BeginBatchDraw();
			xylocation();//采集鼠标位置等
			mouse = getmessage(EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //在作图区执行
			{
				if (mouse.lbutton == 1)
				{
					if (mouse.x < WIDTH && mouse.y > 80)
					{
						if (mouse.message == WM_MOUSEMOVE) {
							if (bmousex != 0 && mousey != 0)//防止从原点开始画
								rectangle(bmousex, bmousey, mousex, mousey);//画矩形
							mousex = mouse.x; mousey = mouse.y;
							if (bmousex != 0 && mousey != 0)//防止从原点开始画
								rectangle(bmousex, bmousey, mousex, mousey);
						}

					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//右键取消当前绘制，将图形覆盖
				{

					rectangle(bmousex, bmousey, mouse.x, mouse.y);
					rectangle(bmousex, bmousey, bmousex, bmousey);
					mousex = mouse.x; mousey = mouse.y;//获取坐标
					break;
				}
				if (mouse.message == WM_LBUTTONUP)
				{
					setlinecolor(RGB(x, y, z));
					setrop2(R2_COPYPEN);
					if (bmousex != 0 && mousey != 0)//防止从原点开始画
						rectangle(bmousex, bmousey, mouse.x, mouse.y);

					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void drawellipse() //画椭圆
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//开始点的位置坐标
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//设置绘制出的像素颜色 = 屏幕颜色 XOR 当前颜色
		while (1)
		{
			BeginBatchDraw();
			xylocation();//采集鼠标位置等
			peekmessage(&mouse, EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //在作图区执行
			{


				if (mouse.lbutton == 1)
				{
						if (ellimask == -1)//椭圆遮罩--防止起点画为椭圆
						{
							ellipse(bmousex, bmousey, bmousex, bmousey);//将起点椭圆覆盖
							ellimask = 0;//关闭椭圆遮罩
						}
						if (mouse.message == WM_MOUSEMOVE) {
							if (bmousex != 0 && mousey != 0)//防止从原点开始画
								ellipse(bmousex, bmousey, mousex, mousey);
							mousex = mouse.x; mousey = mouse.y;
							if (bmousex != 0 && mousey != 0)//防止从原点开始画
								ellipse(bmousex, bmousey, mousex, mousey);
						}
				}
				if (mouse.message == WM_RBUTTONDOWN)//鼠标右键按下--取消当前绘图
				{
					ellipse(bmousex, bmousey, mouse.x, mouse.y);//覆盖原来显示的线条
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//椭圆遮罩启动
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//鼠标左键松下--图像绘制取最终结果
				{
					setlinecolor(RGB(x, y, z));//设置最终的线条颜色
					setrop2(R2_COPYPEN);//设置使用当前颜色
					if (bmousex != 0 && mousey != 0)//防止从原点开始画
						ellipse(bmousex, bmousey, mouse.x, mouse.y);
					ellimask = -1;//椭圆遮罩启动
					break;
				}
			}FlushBatchDraw();
		}
	}
}
int radiuss(int x,int y,int bx,int by)//计算两点之间距离（求半径）
{
	int sum = (x-bx) * (x-bx) + (y-by) * (y-by);
	int distance=sqrt(sum);
	return distance;
	
}
void drawcircle()//画圆
{
	mouse = getmessage(EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//开始点的位置坐标
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//设置绘制出的像素颜色 = 屏幕颜色 XOR 当前颜色
		while (1)
		{
			BeginBatchDraw();
			xylocation();//采集鼠标位置等
			mouse = getmessage(EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80&&((bmousey- radiuss(mouse.x, mouse.y, bmousex, bmousey))>80)) //在作图区执行
			{


				if (mouse.lbutton == 1)
				{
					if (ellimask == -1)//椭圆遮罩--防止起点画为椭圆
					{
						circle(bmousex, bmousey, radiuss(bmousex, bmousey,bmousex,bmousey));//将起点椭圆覆盖
						ellimask = 0;//关闭椭圆遮罩
					}
					if (mouse.message == WM_MOUSEMOVE) {
						if (bmousex != 0 && mousey != 0)//防止从原点开始画
							circle(bmousex, bmousey, radiuss(mousex, mousey, bmousex, bmousey));
						mousex = mouse.x; mousey = mouse.y;
						if (bmousex != 0 && mousey != 0)//防止从原点开始画
							circle(bmousex, bmousey, radiuss(mousex, mousey, bmousex, bmousey));
					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//鼠标右键按下--取消当前绘图
				{
					circle(bmousex, bmousey, radiuss(mouse.x, mouse.y, bmousex, bmousey));//覆盖原来显示的线条
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//椭圆遮罩启动
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//鼠标左键松下--图像绘制取最终结果
				{
					setlinecolor(RGB(x, y, z));//设置最终的线条颜色
					setrop2(R2_COPYPEN);//设置使用当前颜色
					if (bmousex != 0 && mousey != 0)//防止从原点开始画
						circle(bmousex, bmousey, radiuss(mouse.x, mouse.y, bmousex, bmousey));
					ellimask = -1;//椭圆遮罩启动
					break;
				}
			}FlushBatchDraw();
		}
	}
}
void resetr()//设置弧度
{
	if (mouse.x <= 540 && mouse.x >= 420 && mouse.y>= 65 && mouse.y <= 70)
	{
		
		setfillcolor(WHITE);
		if (mouse.message == WM_LBUTTONDOWN)
		{
			emousex = mouse.x;
			emousey = mouse.y;
			solidroundrect(420, 65, 540, 70, 2, 2);
			setfillcolor(BLACK);
			solidroundrect(420, 65, mouse.x, 70, 2, 2);
			setfillcolor(WHITE);
			isdown = 8;
			r2 =2*PI / (double)180.0 * (double)(180.0 * ((double)mouse.x - 420.0) / 120.0);//求出r2，末弧度
			r = r2;//保存末弧度
		}
		if (mouse.message == WM_LBUTTONUP)
		{
			isdown = 0;
		}
		if (isdown == 8 && mouse.message == WM_MOUSEMOVE)
		{
			{
				if (emousex > mouse.x && emousex <= 540 && emousex >= 420)
					solidroundrect(420, 65, 540, 70, 2, 2);
				setfillcolor(BLACK);
				solidroundrect(420, 65, mouse.x, 70, 2, 2);
			}
			r2 = 2 * PI / (double)180.0 * (double)(180.0 * ((double)mouse.x - 420.0) / 120.0);//求出r2，末弧度
			r = r2;//保存末弧度
		}
	}
}
void drawsector()//画扇形
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//开始点的位置坐标
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//设置绘制出的像素颜色 = 屏幕颜色 XOR 当前颜色
		r1 = 0;
		
		while (1)
		{
			BeginBatchDraw();
			xylocation();//采集鼠标位置等
			peekmessage(&mouse, EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //在作图区执行
			{
					if (mouse.x > bmousex&& exchangel == 1)//向右转向
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = PI - r2;
						r2 = PI - temp;
						exchangel = 0;
						exchanger = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
					if (mouse.x < bmousex && exchanger == 1)//向右转向
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = PI - r2;
						r2 = PI - temp;
						exchanger = 0;
						exchangel = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
					if (mouse.y> bmousey && exchanged == 1)//向右转向
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = 2*PI - r2;
						r2 = 2*PI - temp;
						exchanged = 0;
						exchangeu = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
					if (mouse.y < bmousey && exchangeu == 1)//向右转向
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = 2*PI - r2;
						r2 = 2*PI - temp;
						exchangeu = 0;
						exchanged = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}//以上均为通过改变起始弧度和末弧度实现
				if (mouse.lbutton == 1)
				{
					if (ellimask == -1)//椭圆遮罩--防止起点画为椭圆
					{
						pie(bmousex, bmousey, bmousex, bmousey,r1,r2);//将起点覆盖
						ellimask = 0;//关闭椭圆遮罩
					}
					if (mouse.message == WM_MOUSEMOVE) {
						if (bmousex != 0 && mousey != 0)//防止从原点开始画
							pie(bmousex, bmousey, mousex, mousey, r1, r2);
						mousex = mouse.x; mousey = mouse.y;
						if (bmousex != 0 && mousey != 0)//防止从原点开始画
							pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//鼠标右键按下--取消当前绘图
				{
					pie(bmousex, bmousey, mouse.x, mouse.y, r1, r2);//覆盖原来显示的线条
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//椭圆遮罩启动
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//鼠标左键松下--图像绘制取最终结果
				{
					setlinecolor(RGB(x, y, z));//设置最终的线条颜色
					setrop2(R2_COPYPEN);//设置使用当前颜色
					if (bmousex != 0 && mousey != 0)//防止从原点开始画
						pie(bmousex, bmousey, mouse.x, mouse.y,r1, r2);
					r2 = r;
					ellimask = -1;//椭圆遮罩启动
					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void draws() //画圆弧
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//设置绘制出的像素颜色 = 屏幕颜色 XOR 当前颜色
		r1 = 0;
		while (1)
		{
			BeginBatchDraw();
			xylocation();//采集鼠标位置等
			peekmessage(&mouse, EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //在作图区执行
			{
				if (mouse.x > bmousex && exchangel == 1)//向右转向
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = PI - r2;
					r2 = PI - temp;
					exchangel = 0;
					exchanger = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}
				if (mouse.x < bmousex && exchanger == 1)//向右转向
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = PI - r2;
					r2 = PI - temp;
					exchanger = 0;
					exchangel = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}
				if (mouse.y > bmousey && exchanged == 1)//向右转向
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = 2 * PI - r2;
					r2 = 2 * PI - temp;
					exchanged = 0;
					exchangeu = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}
				if (mouse.y < bmousey && exchangeu == 1)//向右转向
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = 2 * PI - r2;
					r2 = 2 * PI - temp;
					exchangeu = 0;
					exchanged = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}//以上均为通过改变起始弧度和末弧度实现
				if (mouse.lbutton == 1)
				{
					if (ellimask == -1)//椭圆遮罩--防止起点画为椭圆
					{
						arc(bmousex, bmousey, bmousex, bmousey, r1, r2);//将起点覆盖
						ellimask = 0;//关闭椭圆遮罩
					}
					if (mouse.message == WM_MOUSEMOVE) {
						if (bmousex != 0 && mousey != 0)//防止从原点开始画
							arc(bmousex, bmousey, mousex, mousey, r1, r2);
						mousex = mouse.x; mousey = mouse.y;
						if (bmousex != 0 && mousey != 0)//防止从原点开始画
							arc(bmousex, bmousey, mousex, mousey, r1, r2);
					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//鼠标右键按下--取消当前绘图
				{
					arc(bmousex, bmousey, mouse.x, mouse.y, r1, r2);//覆盖原来显示的线条
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//椭圆遮罩启动
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//鼠标左键松下--图像绘制取最终结果
				{
					setlinecolor(RGB(x, y, z));//设置最终的线条颜色
					setrop2(R2_COPYPEN);//设置使用当前颜色
					if (bmousex != 0 && mousey != 0)//防止从原点开始画
						arc(bmousex, bmousey, mouse.x, mouse.y, r1, r2);
					r2 = r;
					ellimask = -1;//椭圆遮罩启动
					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void load()//加载自定义颜色
{
	FILE* file = NULL;
	file = fopen(".\\MYRGB\\MYRGB.txt", "r");//打开文件
	if (file == NULL)
		exit(0);
	for (int i = 1;i <= 8;i++)
	{
		fscanf_s(file, "R:%d,G:%d,B:%d\n", MyR+i,MyG+i, MyB+i);
		setlinecolor(0xB7B7B7);//灰色
		setfillcolor(RGB(MyR[i], MyG[i], MyB[i]));
		fillrectangle(750 + 23 * (i-1), 44, 769 + 23 * (i-1), 63);//用方框依次显示文件中的保存的RGB
	}
	fclose(file);//关闭文件夹
}
void save()//保存你自己的颜色
{
	FILE* file = NULL;
	file = fopen(".\\MYRGB\\MYRGB.txt", "w");//打开文件
	if (file == NULL)//没有文件就退出
		exit(0);
	for (int i = 1;i <= 8;i++)
		fprintf(file, "R:%d,G:%d,B:%d\n", MyR[i], MyG[i], MyB[i]);//保存每次的RGB
	for (int i = 1;i <= 8;i++)
	{
		fscanf_s(file, "R:%d,G:%d,B:%d\n", MyR + i, MyG + i, MyB + i);
		setlinecolor(0xB7B7B7);//灰色
		setfillcolor(RGB(MyR[i], MyG[i], MyB[i]));
		fillrectangle(750 + 23 * (i - 1), 44, 769 + 23 * (i - 1), 63);//用方框依次显示文件中的保存的RGB
	}
	fclose(file);//关闭文件夹
}
void saveimage()//保存图片
{
	if (mouse.x >= 420 && mouse.x <= 450 && mouse.y <= 30&&mouse.message==WM_LBUTTONDOWN)//保存图片上按下
	{	
	TCHAR fileName[100];//定义一个TCHAT类型的变量
	TCHAR l[50];
	getimage(&saveimg, 0, 81, 960, 640-81);//获取绘图区的句柄
	InputBox(l, 50, L"请输入文件的名字:");
	_stprintf(fileName,_T( "./saveimg/%ls.png"), l);//转换类型
	saveimage(fileName, &saveimg);//保存图片
	TCHAR link[50] = _T("文件成功保存至路径:\n");
	_tcscat(link,fileName);//连接
	MessageBox(NULL, link, _T("保存成功"), MB_ICONINFORMATION | MB_SYSTEMMODAL);//打印filename的在弹窗中

	}
}
void explan()//说明
{
	if (mouse.x >= 460 && mouse.x <= 490 && mouse.y <= 30 && mouse.message == WM_LBUTTONDOWN)//在说明图片上按下
	{
		while (1)
		{
			if (MessageBox(NULL, _T("说明：\n这是画图软件\n作者：Ansel09"), _T("说明"), MB_ICONINFORMATION | MB_SYSTEMMODAL))//有操作就退出
				break;
		}
	}
}
void openimg()
{
	if (_kbhit())
	{
		char input = _getch();
		if (input == 'o')
		{
			TCHAR openfile[200];
			IMAGE back;
			InputBox(openfile, 200, L"输入打开文件");
			loadimage(&back, openfile);
			putimage(0, 81, &back);
		}

	}
}