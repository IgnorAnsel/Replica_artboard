
#include"all.h"//��������ͷ�ļ�


int MyR[10] = { 1 ,0,0,0,0,0,0,0,0,0 }, MyG[10] = { 1,0,0,0,0,0,0,0,0,0 }, MyB[10] = { 0 ,0,0,0,0,0,0,0,0,0 };//�Զ�����ɫ����
int main()
{
	{
		
		initgraph(WIDTH, HIGHT);//���廭��
	setbkcolor(WHITE);//���ñ�����ɫ
	cleardevice();//
	uishow();//һЩͼ��������
	xylocation();//��ʾxy����
	loadimage(&pic[0], _T(".\\images\\1 (1).png"));
	loadimage(&pic[1], _T(".\\images\\1 (2).png"));
	loadimage(&pic[2], _T(".\\images\\1 (3).png"));
	loadimage(&pic[3], _T(".\\images\\1 (4).png"));//���ع���ͼ��
	loadimage(&picpen, _T(".\\�ޱ���.png"));//���ر���ʽͼ��
	loadimage(&form, _T(".\\images\\1.png"));//����ͼ��ͼ��
	loadimage(&colorline, _T(".\\images\\ɫ��.png"));//���ع̶�ɫ��
	loadimage(&mycolorline, _T(".\\images\\�Զ���ɫ��.png"));//�����Զ���ɫ��װ�
	loadimage(&savep, _T(".\\����.png"));//���ر��水��ͼ��
	loadimage(&explainp, _T(".\\˵��.png"));//����˵������ͼ��
	loadimage(&exitp, _T(".\\�˳�.png"));//�����˳�����ͼ��
	loadimage(&explanishow, _T(".\\˵������.png"));
	putimage(230, 5, &picpen);
	putimage(420, 40, &form);
	putimage(750, 14, &colorline);
	putimage(750, 44, &mycolorline);
	putimage(420, 0, &savep);

	
	putimage(460, 0, &explainp);//����һЩ����ͼƬ
	BeginBatchDraw();//��ʼ������ͼ
	load();//�����Զ�����ɫ
	//save();//�����Զ�����ɫ
	}//Ԥ����
	while (1)//ѭ��
	{
		openimg();//��ͼƬ
		setrop2(R2_COPYPEN);//��ɫģʽΪ��ǰ��ɫ
		avoidbug();//��ֹ����������ͼ����bug
		MouseChange();//��ȡ��ǰ���λ��
		menu();//�˵�����ѡ��
		formchose();//��ͼ��ʽѡ��
		avoidbug();//��ֹ����������ͼ
		linethickness();//������ϸѡ��
		setlinestyle(0);//�ָ�����Ϊʵ��
		Resetlinestyle();//����������ʽ
		resetr();//���ýǶ�
		ResetColor();//������ɫ
		SetColor();//ѡ������������ɫ
		SetMyColor();//ѡ���Զ�����ɫ
		uishow();//һЩͼ��������
		MouseChange();//��ȡ��ǰ���λ��
		explan();//˵��
		saveimage();//����ͼƬ
		EndBatchDraw();//����������ͼ
		
	}
	_getch();//����
	closegraph();//�رջ���
}
void menu() //��Ҫ����
{
	setlinecolor(BLACK);//��ɫ��ɫ
	setlinestyle(PS_SOLID, 1);//1���ʵ��
	roundrect(225, 6 + 12 * penstyle, 295, 15 + 12 * penstyle, 2, 2);//��ǰ������ʽѡ���
	peekmessage(&mouse, EM_MOUSE);//��ȡ�����Ϣ
	if (mouse.x >= 0 && mouse.x <= 960 && mouse.y >= 80+linethick/2 && mouse.y <= 640)//���λ����ͼ��
	{
		setlinestyle(penstyle);//���û�����ʽ
		if (functionnum == 0)//���ܣ�������������
			Freedrawing();
		if (functionnum == 1)//���ܣ��������
			Fill();
		if (functionnum == 2)//���ܣ���Ƥ��
			clean();
		if (functionnum == 3)
			getColor();

			xylocation();//��ʾxy����λ��
	}
	allclean();//ȫ���������
	
}
void avoidbug()//��ֹ����������ͼ
{
	if (mouse.lbutton != 1|| mouse.message == WM_LBUTTONUP)
		isdown = 0;//���δ����
}
void MouseChange()//���ϻ�ȡǰһ��mouse��xy
{
	if (mouse.x >= 0 && mouse.x <= 960 && mouse.y >= 80 && mouse.y <= 640)//���λ����ͼ��
	{
		mousex = mouse.x;
		mousey = mouse.y;
	}
	else//�ڹ�������õ��ǹ�������ǰһ��mouse��xy
	{
		emousex = mouse.x;
		emousey = mouse.y;
	}
}
void Resetlinestyle()//����������ʽ
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
void uishow()//����չʾ
{
	setlinecolor(BLACK);
	line(0, 80, 960, 80);//�ָ��ߣ���������Ϊ�������ͻ�ͼ��
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	roundrect(420, 65, 540, 70, 1, 1);
	roundrect(310, 4, 320, 69, 2, 2);
	roundrect(600, 20, 700, 30, 2, 2);//RGB��ɫ���ӡ�ı߿�
	_stprintf(s, _T("��:%.2lf"), r2);//������ʾ
	outtextxy(550, 63, s);//������ʾ
	_stprintf(s, _T("%02d"), linethick);//������ϸ��ʾ
	outtextxy(335, 63, s);//������ϸ��ʾ
	_stprintf(s, _T("R:%03d"), x);
	outtextxy(703, 17, s);
	roundrect(600, 35, 700, 45, 2, 2);
	_stprintf(s, _T("G:%03d"), y);
	outtextxy(703, 32, s);
	roundrect(600, 50, 700, 60, 2, 2);
	_stprintf(s, _T("B:%03d"), z);
	outtextxy(703, 47, s);//RGB��ʾ
	outtextxy(2, 5, L"NOW COLOR");//��ӡ����NOW COLOR
	for (int i = 0;i <= 3;i++)
	{
		putimage(90 + i * 32, 25, &pic[i]);//���δ�ӡ����ͼƬ
		if (mouse.x >= 90 + i * 32 && mouse.x < 120 + i * 32 && mouse.y >= 25 && mouse.y <= 53)
			if (mouse.message == WM_LBUTTONDOWN)
			{
				setlinecolor(WHITE);
				roundrect(89 + functionnum * 32, 24, 121 + functionnum * 32, 54, 4, 4);//���Ǵ�ѡ����
				functionnum = i;
				roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);//����ͼ�����ȷ���Ĺ���
				formsure = -100;//ͼ�����ȷ��-100
			}
	}
	setlinecolor(BLACK);
	roundrect(89 + functionnum * 32, 24, 121 + functionnum * 32, 54, 4, 4);//��ѡ���ܿ�
}
void getColor()//��ȡ��ǰ��ɫ
{
	if (mouse.message == WM_LBUTTONDOWN)
	{
		x = GetRValue(getpixel(mouse.x, mouse.y));
		y = GetGValue(getpixel(mouse.x, mouse.y));
		z = GetBValue(getpixel(mouse.x, mouse.y));//ʹ�û�ȡRGB��ɫ�ĺ���
	}
	
}
void Freedrawing()//���ɻ�������
{
	
	if (mouse.message == WM_LBUTTONDOWN)//����������
	{
		BeginBatchDraw();//�������ƿ�ʼ
		mousex = mouse.x;
		mousey = mouse.y;
		isdown = 1;
	}
	if (mouse.message == WM_LBUTTONUP)//����������
	{
		FlushBatchDraw();//�������ƽ���
		isdown = 0;
	}
	if (isdown == 1 && mouse.message == WM_MOUSEMOVE)//�������²����ƶ�
	{
		setlinecolor(RGB(x, y, z));//����Ϊ��ǰ��ɫ
		setlinestyle(penstyle,linethick);//���û���Ϊ��ǰ��ϸ����ʽ
		line(mousex, mousey, mouse.x, mouse.y);//ͨ�����ϻ�ȡǰһ�����λ��ʹ��������ʵ�����ɻ滭
	}

}
void Fill()//��ɫ���
{
	if (mouse.message == WM_LBUTTONDOWN)//����������
	{
		setfillcolor(RGB(x, y, z));//����Ϊ��ǰ��ɫ
		setfillstyle(BS_SOLID);//�������Ϊ����ʵ��
		mousex = mouse.x;
		mousey = mouse.y;
		floodfill(mousex, mousey, getpixel(mousex, mousey), 1);//ʹ��flooffill����������getpixelʶ����ɫ���������Ϊ1����ִ��Ϊʹʶ�𵽵���ɫ�ڱ߽��ڱ�Ϊ����ֵ����ɫ
	}
}
void SetColor()//ѡ������������ɫ -----��ʽ��fromsure����һ��
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
	case 7:y = 0;x = z = 255;break;//��RGB����Ϊѡ�����ɫ
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
	solidroundrect(600, 51, 600+ 100*z/255,59, 2, 2);}//��RGB����Ϊѡ�����ɫ
}
void SetMyColor()//ѡ�������Լ��������ɫ -----��ʽ��fromsure����һ��
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
		rectangle(749 + 23 * mycolornum, 43, 770 + 23 * mycolornum, 64);//���Ǵ�ѡ����ɫ
		setlinecolor(BLACK);
		rectangle(749 + 23 * mycolorsure, 43, 770 + 23 * mycolorsure, 64);//��ӡ��ǰѡ����ɫ�߿�
	}
	if (mycolorsure >= 0)//ȷ���Զ�����ɫ
	{
		cc1++;
		if (cc1 == 100)
		{

			cc1 = 0;
			load();
			x = MyR[mycolorsure + 1];
			y = MyG[mycolorsure + 1];
			z = MyB[mycolorsure + 1];//��ȡ��ɫ
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
		solidroundrect(600, 51, 600 + 100 * z / 255, 59, 2, 2);//��RGB����Ϊѡ�����ɫ
	}
	
}
void ResetColor()//����������ɫ
{
	setfillcolor(WHITE);
	if (mouse.x >= 600 && mouse.x <= 700 && mouse.y >= 20 && mouse.y <= 30 && mouse.lbutton == 1)
	{
		ResetColorRed();
		
		colorsure = -100;//��ɫѡ��-100
		//mycolorsure = -100;
	}
	if (mouse.x >= 600 && mouse.x <= 700 && mouse.y >= 35 && mouse.y <= 45 && mouse.lbutton == 1)
	{
		ResetColorGreen();
		
		colorsure = -100;//��ɫѡ��-100
		//mycolorsure = -100;
	}
	if (mouse.x >= 600 && mouse.x <= 700 && mouse.y >= 50 && mouse.y <= 60 && mouse.lbutton == 1)
	{
		ResetColorBlue();
		//mycolorsure = -100;
		colorsure = -100;//��ɫѡ��-100
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
			MyB[c] = (int)z;//��ȡ��ɫֵ
			save();
			setlinecolor(0xB7B7B7);
			setfillcolor(RGB(MyR[c], MyG[c], MyB[c]));
			fillrectangle(750 + 23 * (mycolorsure), 44, 769 + 23 * (mycolorsure), 63);//�Զ�����ɫѡ��;
		}
		
	}
}
void ResetColorRed()//����R
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
			if (emousex > mouse.x&&emousex<=700&&emousex>=600)//�������
				solidroundrect(emousex, 21, 700, 29,2,2);
			setfillcolor(RGB(x,0,0));
			solidroundrect(600, 21, mouse.x, 29,2,2);
		}
		x = 255 * (mouse.x - 600) / 100;
	}
}
void xylocation()//��ʾxy����
{
	setbkmode(OPAQUE);
	settextcolor(BLACK);
	_stprintf(s, _T("X:%03d  Y:%03d"), mouse.x,mouse.y-80);
	outtextxy(5, 60,s);//XY������
	_stprintf(s, _T("BX:%03d  BY:%03d"), bmousex, bmousey - 80);
	outtextxy(120, 60, s);//��ʼXY����
	clearrectangle(90, 10, 210, 25);
	_stprintf(s, _T("CX:%03d"), mouse.x-bmousex);
	outtextxy(100, 10, s);//x�Ĳ�ֵ
	_stprintf(s, _T("CY:%03d"),mouse.y - 80 - (bmousey - 80));
	outtextxy(160, 10, s);//y�Ĳ�ֵ
}
void ResetColorGreen()//����G
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
			if (emousex > mouse.x && emousex <= 700 && emousex >= 600)//�������
				solidroundrect(emousex, 36, 700, 44,2,2);
			setfillcolor(RGB(0,y,0));
			solidroundrect(601, 36, mouse.x, 44,2,2);
		}
		y = 255 * (mouse.x - 600) / 100;
	}
}
void ResetColorBlue()//����B
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
			if (emousex > mouse.x && emousex <= 700 && emousex >= 600)//�������
				solidroundrect(emousex, 51, 700, 59,2,2);
			setfillcolor(RGB(0,0,z));
			solidroundrect(600, 51, mouse.x, 59,2,2);
		}
		z= 255 * (mouse.x - 600) / 100;
	}
}
void linethickness()//������ϸ����
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
			linethick =30*(70 - mouse.y)/69+1 ;//���������ϸ
			setfillcolor(BLACK);
			solidcircle(365, 35, linethick);//ͨ��Բ����Ӧ
		}
	}
}
void clean()//��Ƥ�ߣ�ʵ����Ϊ��ɫ���ʣ�
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
void allclean()//��ջ���
{
	if (mouse.x >= 90 + 2 * 32 && mouse.x < 120 + 2 * 32 && mouse.y >= 25 && mouse.y <= 53 && mouse.lbutton == 1)//����Ƥ��ͼƬ��
		count++;//һֱ�������������
	else
		count = 0;//δ���������Ϊ0
	if (count >= 3000)//�䵱ʱ��ƴΣ������͵�����ʾ��
	{
		//MessageBox(NULL, _T("�Ƿ�ȫ�������"), _T("��ʾ"), MB_OKCANCEL|MB_ICONQUESTION|MB_SYSTEMMODAL);
		if (MessageBox(NULL, _T("�Ƿ�ȫ�������"), _T("��ʾ"), MB_OKCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL) == IDOK)//���ѡ�����ȷ�����������
			clearrectangle(0, 81, 960, 640);//�����ͼ��
		count = 0;
	}
}
void formchose()//����ͼ�λ��Ƶ�ѡ��
{
	if (mouse.x >= 420 && mouse.x <= 540 && mouse.y >= 40 && mouse.y <= 60) //��ͼ��ѡ������
	{
		setlinestyle(PS_SOLID, 1);//����Ϊ1��ȵ�ʵ��
		for (int i = 0;i <= 5;i++)//�������ͼ�����
			if (mouse.x >= 420 + i * 20 && mouse.x < 440 + i * 20 && mouse.y >= 40 && mouse.y <= 60)//���ĸ�ͼ�������
			{
				peekmessage(&mouse, EM_MOUSE);
				if (i != formnum)//�����ǰ����ͬһ������ѡ���
				{
					setlinecolor(WHITE);
					roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//���ǰһ��
				}
				formnum = i;//ȷ������ѡͼ�����
				if (mouse.message == WM_LBUTTONDOWN)//���������
				{
					
					setlinecolor(WHITE);
					roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);
					formsure = i;//���õ�ǰȷ����ͼ�����
				}
				setlinecolor(0x7F7F7F);//������ɫΪ��ɫ
				roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//���Ƴ���ǰ��ѡͼ�����
				setlinecolor(BLACK);//����Ϊ��ɫ
				roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);//���Ƴ���ǰȷ����ͼ�����
			}
	}
	else
	{
		setlinestyle(PS_SOLID, 1);//����Ϊ1��ȵ�ʵ��
		setlinecolor(WHITE);//������ɫ��ɫ
		roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//���Ǵ�ѡͼƬ���
		formnum = -100;//��ѡ��-100
		setlinecolor(BLACK);//������ɫ��ɫ
		roundrect(419 + formsure * 20, 39, 440 + formsure * 20, 61, 1, 1);//���Ƴ���ǰȷ����ͼ�����
	}
	if (formsure>=0)//����Լ���ѡ���ͼ�����
	{
		setlinecolor(WHITE);//��ɫ��ɫ
		setlinestyle(PS_SOLID, 1);//����Ϊ1��ȵ�ʵ��
		roundrect(89 + functionnum * 32, 24, 121 + functionnum * 32, 54, 4, 4);//���ܵ�ѡ�����
		functionnum = -100;//����ѡ����-100

	}
	if (mouse.x >= 0 && mouse.x <= 960 && mouse.y >= 80 && mouse.y <= 640)//���λ����ͼ��
	{
		setlinecolor(WHITE);//��ɫ��ɫ
		roundrect(419 + formnum * 20, 39, 440 + formnum * 20, 61, 1, 1);//���Ǵ�ѡͼƬ���
		formnum = -100;//��ѡ��-100
		if (formsure == 0)//ͼ�����0
		    drawline();//��ֱ��
		if (formsure == 1)//ͼ�����1
			draws();//��Բ��
		if (formsure == 2)//ͼ�����2
			drawsector();//������
		if (formsure == 3)//ͼ�����3
			drawcircle();//��Բ
		if (formsure == 4)//ͼ�����4
			drawellipse();//����Բ
		if (formsure == 5)//ͼ�����5
			drawbox();//������
		

	}
}
void drawline()//��ֱ��
{
	mouse = getmessage(EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//��ʼ���λ������
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);
		while (1)
		{
			BeginBatchDraw();
			xylocation();//�ɼ����λ�õ�
			mouse = getmessage(EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //����ͼ��ִ��
			{


				if (mouse.lbutton == 1)
				{
					if (mouse.x < WIDTH && mouse.y > 80)
					{
						if (mouse.message == WM_MOUSEMOVE) {
							if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
								line(bmousex, bmousey, mousex, mousey);//ֱ�߻���
							mousex = mouse.x; mousey = mouse.y;
							if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
								line(bmousex, bmousey, mousex, mousey);
						}

					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//�Ҽ�ȡ����ǰ���ƣ���ͼ�θ���
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
					if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
						line(bmousex, bmousey, mouse.x, mouse.y);

					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void drawbox()//���λ���
{
	mouse = getmessage(EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//��ʼ���λ������
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);
		while (1)
		{
			BeginBatchDraw();
			xylocation();//�ɼ����λ�õ�
			mouse = getmessage(EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //����ͼ��ִ��
			{
				if (mouse.lbutton == 1)
				{
					if (mouse.x < WIDTH && mouse.y > 80)
					{
						if (mouse.message == WM_MOUSEMOVE) {
							if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
								rectangle(bmousex, bmousey, mousex, mousey);//������
							mousex = mouse.x; mousey = mouse.y;
							if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
								rectangle(bmousex, bmousey, mousex, mousey);
						}

					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//�Ҽ�ȡ����ǰ���ƣ���ͼ�θ���
				{

					rectangle(bmousex, bmousey, mouse.x, mouse.y);
					rectangle(bmousex, bmousey, bmousex, bmousey);
					mousex = mouse.x; mousey = mouse.y;//��ȡ����
					break;
				}
				if (mouse.message == WM_LBUTTONUP)
				{
					setlinecolor(RGB(x, y, z));
					setrop2(R2_COPYPEN);
					if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
						rectangle(bmousex, bmousey, mouse.x, mouse.y);

					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void drawellipse() //����Բ
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//��ʼ���λ������
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//���û��Ƴ���������ɫ = ��Ļ��ɫ XOR ��ǰ��ɫ
		while (1)
		{
			BeginBatchDraw();
			xylocation();//�ɼ����λ�õ�
			peekmessage(&mouse, EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //����ͼ��ִ��
			{


				if (mouse.lbutton == 1)
				{
						if (ellimask == -1)//��Բ����--��ֹ��㻭Ϊ��Բ
						{
							ellipse(bmousex, bmousey, bmousex, bmousey);//�������Բ����
							ellimask = 0;//�ر���Բ����
						}
						if (mouse.message == WM_MOUSEMOVE) {
							if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
								ellipse(bmousex, bmousey, mousex, mousey);
							mousex = mouse.x; mousey = mouse.y;
							if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
								ellipse(bmousex, bmousey, mousex, mousey);
						}
				}
				if (mouse.message == WM_RBUTTONDOWN)//����Ҽ�����--ȡ����ǰ��ͼ
				{
					ellipse(bmousex, bmousey, mouse.x, mouse.y);//����ԭ����ʾ������
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//��Բ��������
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//����������--ͼ�����ȡ���ս��
				{
					setlinecolor(RGB(x, y, z));//�������յ�������ɫ
					setrop2(R2_COPYPEN);//����ʹ�õ�ǰ��ɫ
					if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
						ellipse(bmousex, bmousey, mouse.x, mouse.y);
					ellimask = -1;//��Բ��������
					break;
				}
			}FlushBatchDraw();
		}
	}
}
int radiuss(int x,int y,int bx,int by)//��������֮����루��뾶��
{
	int sum = (x-bx) * (x-bx) + (y-by) * (y-by);
	int distance=sqrt(sum);
	return distance;
	
}
void drawcircle()//��Բ
{
	mouse = getmessage(EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//��ʼ���λ������
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//���û��Ƴ���������ɫ = ��Ļ��ɫ XOR ��ǰ��ɫ
		while (1)
		{
			BeginBatchDraw();
			xylocation();//�ɼ����λ�õ�
			mouse = getmessage(EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80&&((bmousey- radiuss(mouse.x, mouse.y, bmousex, bmousey))>80)) //����ͼ��ִ��
			{


				if (mouse.lbutton == 1)
				{
					if (ellimask == -1)//��Բ����--��ֹ��㻭Ϊ��Բ
					{
						circle(bmousex, bmousey, radiuss(bmousex, bmousey,bmousex,bmousey));//�������Բ����
						ellimask = 0;//�ر���Բ����
					}
					if (mouse.message == WM_MOUSEMOVE) {
						if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
							circle(bmousex, bmousey, radiuss(mousex, mousey, bmousex, bmousey));
						mousex = mouse.x; mousey = mouse.y;
						if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
							circle(bmousex, bmousey, radiuss(mousex, mousey, bmousex, bmousey));
					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//����Ҽ�����--ȡ����ǰ��ͼ
				{
					circle(bmousex, bmousey, radiuss(mouse.x, mouse.y, bmousex, bmousey));//����ԭ����ʾ������
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//��Բ��������
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//����������--ͼ�����ȡ���ս��
				{
					setlinecolor(RGB(x, y, z));//�������յ�������ɫ
					setrop2(R2_COPYPEN);//����ʹ�õ�ǰ��ɫ
					if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
						circle(bmousex, bmousey, radiuss(mouse.x, mouse.y, bmousex, bmousey));
					ellimask = -1;//��Բ��������
					break;
				}
			}FlushBatchDraw();
		}
	}
}
void resetr()//���û���
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
			r2 =2*PI / (double)180.0 * (double)(180.0 * ((double)mouse.x - 420.0) / 120.0);//���r2��ĩ����
			r = r2;//����ĩ����
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
			r2 = 2 * PI / (double)180.0 * (double)(180.0 * ((double)mouse.x - 420.0) / 120.0);//���r2��ĩ����
			r = r2;//����ĩ����
		}
	}
}
void drawsector()//������
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;//��ʼ���λ������
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//���û��Ƴ���������ɫ = ��Ļ��ɫ XOR ��ǰ��ɫ
		r1 = 0;
		
		while (1)
		{
			BeginBatchDraw();
			xylocation();//�ɼ����λ�õ�
			peekmessage(&mouse, EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //����ͼ��ִ��
			{
					if (mouse.x > bmousex&& exchangel == 1)//����ת��
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = PI - r2;
						r2 = PI - temp;
						exchangel = 0;
						exchanger = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
					if (mouse.x < bmousex && exchanger == 1)//����ת��
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = PI - r2;
						r2 = PI - temp;
						exchanger = 0;
						exchangel = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
					if (mouse.y> bmousey && exchanged == 1)//����ת��
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = 2*PI - r2;
						r2 = 2*PI - temp;
						exchanged = 0;
						exchangeu = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
					if (mouse.y < bmousey && exchangeu == 1)//����ת��
					{
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
						double temp = r1;
						r1 = 2*PI - r2;
						r2 = 2*PI - temp;
						exchangeu = 0;
						exchanged = 1;
						pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}//���Ͼ�Ϊͨ���ı���ʼ���Ⱥ�ĩ����ʵ��
				if (mouse.lbutton == 1)
				{
					if (ellimask == -1)//��Բ����--��ֹ��㻭Ϊ��Բ
					{
						pie(bmousex, bmousey, bmousex, bmousey,r1,r2);//����㸲��
						ellimask = 0;//�ر���Բ����
					}
					if (mouse.message == WM_MOUSEMOVE) {
						if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
							pie(bmousex, bmousey, mousex, mousey, r1, r2);
						mousex = mouse.x; mousey = mouse.y;
						if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
							pie(bmousex, bmousey, mousex, mousey, r1, r2);
					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//����Ҽ�����--ȡ����ǰ��ͼ
				{
					pie(bmousex, bmousey, mouse.x, mouse.y, r1, r2);//����ԭ����ʾ������
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//��Բ��������
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//����������--ͼ�����ȡ���ս��
				{
					setlinecolor(RGB(x, y, z));//�������յ�������ɫ
					setrop2(R2_COPYPEN);//����ʹ�õ�ǰ��ɫ
					if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
						pie(bmousex, bmousey, mouse.x, mouse.y,r1, r2);
					r2 = r;
					ellimask = -1;//��Բ��������
					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void draws() //��Բ��
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		bmousex = mouse.x;bmousey = mouse.y;
		mousex = mouse.x, mousey = mouse.y;
		setlinecolor(WHITE);
		setlinestyle(penstyle, linethick);
		setrop2(R2_XORPEN);//���û��Ƴ���������ɫ = ��Ļ��ɫ XOR ��ǰ��ɫ
		r1 = 0;
		while (1)
		{
			BeginBatchDraw();
			xylocation();//�ɼ����λ�õ�
			peekmessage(&mouse, EM_MOUSE);
			if (mouse.x < WIDTH && mouse.y > 80) //����ͼ��ִ��
			{
				if (mouse.x > bmousex && exchangel == 1)//����ת��
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = PI - r2;
					r2 = PI - temp;
					exchangel = 0;
					exchanger = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}
				if (mouse.x < bmousex && exchanger == 1)//����ת��
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = PI - r2;
					r2 = PI - temp;
					exchanger = 0;
					exchangel = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}
				if (mouse.y > bmousey && exchanged == 1)//����ת��
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = 2 * PI - r2;
					r2 = 2 * PI - temp;
					exchanged = 0;
					exchangeu = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}
				if (mouse.y < bmousey && exchangeu == 1)//����ת��
				{
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
					double temp = r1;
					r1 = 2 * PI - r2;
					r2 = 2 * PI - temp;
					exchangeu = 0;
					exchanged = 1;
					arc(bmousex, bmousey, mousex, mousey, r1, r2);
				}//���Ͼ�Ϊͨ���ı���ʼ���Ⱥ�ĩ����ʵ��
				if (mouse.lbutton == 1)
				{
					if (ellimask == -1)//��Բ����--��ֹ��㻭Ϊ��Բ
					{
						arc(bmousex, bmousey, bmousex, bmousey, r1, r2);//����㸲��
						ellimask = 0;//�ر���Բ����
					}
					if (mouse.message == WM_MOUSEMOVE) {
						if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
							arc(bmousex, bmousey, mousex, mousey, r1, r2);
						mousex = mouse.x; mousey = mouse.y;
						if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
							arc(bmousex, bmousey, mousex, mousey, r1, r2);
					}
				}
				if (mouse.message == WM_RBUTTONDOWN)//����Ҽ�����--ȡ����ǰ��ͼ
				{
					arc(bmousex, bmousey, mouse.x, mouse.y, r1, r2);//����ԭ����ʾ������
					mousex = mouse.x; mousey = mouse.y;
					ellimask = -1;//��Բ��������
					break;
				}
				if (mouse.message == WM_LBUTTONUP)//����������--ͼ�����ȡ���ս��
				{
					setlinecolor(RGB(x, y, z));//�������յ�������ɫ
					setrop2(R2_COPYPEN);//����ʹ�õ�ǰ��ɫ
					if (bmousex != 0 && mousey != 0)//��ֹ��ԭ�㿪ʼ��
						arc(bmousex, bmousey, mouse.x, mouse.y, r1, r2);
					r2 = r;
					ellimask = -1;//��Բ��������
					break;
				}
			}
			FlushBatchDraw();
		}
	}
}
void load()//�����Զ�����ɫ
{
	FILE* file = NULL;
	file = fopen(".\\MYRGB\\MYRGB.txt", "r");//���ļ�
	if (file == NULL)
		exit(0);
	for (int i = 1;i <= 8;i++)
	{
		fscanf_s(file, "R:%d,G:%d,B:%d\n", MyR+i,MyG+i, MyB+i);
		setlinecolor(0xB7B7B7);//��ɫ
		setfillcolor(RGB(MyR[i], MyG[i], MyB[i]));
		fillrectangle(750 + 23 * (i-1), 44, 769 + 23 * (i-1), 63);//�÷���������ʾ�ļ��еı����RGB
	}
	fclose(file);//�ر��ļ���
}
void save()//�������Լ�����ɫ
{
	FILE* file = NULL;
	file = fopen(".\\MYRGB\\MYRGB.txt", "w");//���ļ�
	if (file == NULL)//û���ļ����˳�
		exit(0);
	for (int i = 1;i <= 8;i++)
		fprintf(file, "R:%d,G:%d,B:%d\n", MyR[i], MyG[i], MyB[i]);//����ÿ�ε�RGB
	for (int i = 1;i <= 8;i++)
	{
		fscanf_s(file, "R:%d,G:%d,B:%d\n", MyR + i, MyG + i, MyB + i);
		setlinecolor(0xB7B7B7);//��ɫ
		setfillcolor(RGB(MyR[i], MyG[i], MyB[i]));
		fillrectangle(750 + 23 * (i - 1), 44, 769 + 23 * (i - 1), 63);//�÷���������ʾ�ļ��еı����RGB
	}
	fclose(file);//�ر��ļ���
}
void saveimage()//����ͼƬ
{
	if (mouse.x >= 420 && mouse.x <= 450 && mouse.y <= 30&&mouse.message==WM_LBUTTONDOWN)//����ͼƬ�ϰ���
	{	
	TCHAR fileName[100];//����һ��TCHAT���͵ı���
	TCHAR l[50];
	getimage(&saveimg, 0, 81, 960, 640-81);//��ȡ��ͼ���ľ��
	InputBox(l, 50, L"�������ļ�������:");
	_stprintf(fileName,_T( "./saveimg/%ls.png"), l);//ת������
	saveimage(fileName, &saveimg);//����ͼƬ
	TCHAR link[50] = _T("�ļ��ɹ�������·��:\n");
	_tcscat(link,fileName);//����
	MessageBox(NULL, link, _T("����ɹ�"), MB_ICONINFORMATION | MB_SYSTEMMODAL);//��ӡfilename���ڵ�����

	}
}
void explan()//˵��
{
	if (mouse.x >= 460 && mouse.x <= 490 && mouse.y <= 30 && mouse.message == WM_LBUTTONDOWN)//��˵��ͼƬ�ϰ���
	{
		while (1)
		{
			if (MessageBox(NULL, _T("˵����\n���ǻ�ͼ���\n���ߣ�Ansel09"), _T("˵��"), MB_ICONINFORMATION | MB_SYSTEMMODAL))//�в������˳�
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
			InputBox(openfile, 200, L"������ļ�");
			loadimage(&back, openfile);
			putimage(0, 81, &back);
		}

	}
}