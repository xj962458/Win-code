void hui_qi()
{
    if (step < 2)
    {
        HWND wnd = GetHWnd(); //��ȡ���ھ��
        MessageBox(wnd, "��Ҫ̫̰���ϣ��Ѿ����ܻ�����", "����", MB_OK);
        return;
    }
    bool flag = false; //�����ж���һ���ܷ���������
    for (step -= 1; step > 0; step--)
    { //����һ�ؿ�ʼ����
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                if (historymap[step][i][j] != 0)
                {                //����ʷ������ĳһλ�ò�Ϊ0����˵��������̿��ã���Ϊ��������ʱ�Ѿ�����������ж�
                    flag = true; //������̿���
                    break;
                }
            if (flag)
                break;
        }
        if (flag)
        { //�����������
            copymap(mapp, historymap[step]);
            break;
        }
    }
    int i, j;
    int tstep = step, tMYCOLOR = MYCOLOR, tdiff = diff, tNOWCOLOR = NOWCOLOR;
    int tmapp[SIZE][SIZE], thistorymap[100][SIZE][SIZE];
    bool tsingle = single;
    copymap(tmapp, mapp);
    for (i = 0; i <= tstep; i++)
        copymap(thistorymap[i], historymap[i]);
    init();
    step = tstep, MYCOLOR = tMYCOLOR, diff = tdiff, single = tsingle, NOWCOLOR = 1 - tNOWCOLOR;
    copymap(mapp, tmapp);
    for (i = 0; i <= tstep; i++)
        copymap(historymap[i], thistorymap[i]);
    whitecount = blackcount = 0;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            if (mapp[i][j] == 1)
                blackcount++;
            else if (mapp[i][j] == -1)
                whitecount++;
        }

    printmapp();
    Printcount(blackcount, whitecount, NOWCOLOR); //��ǰ����
    Statistics(MYCOLOR);

    HWND wnd = GetHWnd(); //��ȡ���ھ��
    MessageBox(wnd, "����ɹ�", "����", MB_OK);
}