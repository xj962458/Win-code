void hui_qi()
{
    if (step < 2)
    {
        HWND wnd = GetHWnd(); //获取窗口句柄
        MessageBox(wnd, "不要太贪心呦，已经不能悔棋了", "悔棋", MB_OK);
        return;
    }
    bool flag = false; //用于判断这一把能否悔棋后下棋
    for (step -= 1; step > 0; step--)
    { //从上一回开始计算
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                if (historymap[step][i][j] != 0)
                {                //若历史棋盘在某一位置不为0，则说明这个棋盘可用，因为保存棋盘时已经有能下棋的判断
                    flag = true; //这个棋盘可用
                    break;
                }
            if (flag)
                break;
        }
        if (flag)
        { //备份这个棋盘
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
    Printcount(blackcount, whitecount, NOWCOLOR); //当前形势
    Statistics(MYCOLOR);

    HWND wnd = GetHWnd(); //获取窗口句柄
    MessageBox(wnd, "悔棋成功", "悔棋", MB_OK);
}