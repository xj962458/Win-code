
        temp->next = NULL;
        cout << " 目录创建成功!" << endl;
    }
}

//创建文件
void FileClass::Create()
{
    temp = InitFile(" ", 0);
    cin >> temp->filename;
    cin >> temp->filecontent;
    if (recent->child == NULL)
    {
        temp->parent = recent;
        temp->child = NULL;
        recent->child = temp;
        temp->pre = temp->next = NULL;
        cout << " 文件创建成功!" << endl;
    }
    else
    {
        ttemp = recent->child;
        while (ttemp->next)
        {
            ttemp = ttemp->next;
            if (ttemp->filename == temp->filename && ttemp->isdir == 0)
            {
                cout << " 文件已存在!" << endl;
                return;
            }
        }
        ttemp->next = temp;
        temp->parent = NULL;
        temp->child = NULL;
        temp->pre = ttemp;
        temp->next = NULL;
        cout << " 文件创建成功!" << endl;
    }
}

//显示文件和目录
void FileClass::Dir()
{
    int i = 0, j = 0;
    temp = recent;
    if (temp != root)
    {
        cout << " <目录> .." << endl;
        i++;
    }
    if (temp->child == NULL)
    {
        cout << "总计:"
             << " 目录:" << i << "\t文件:" << j << endl;
        return;
    }
    temp = temp->child;
    while (temp != NULL)
    {
        if (temp->isdir)
        {
            cout << " <目录> " << temp->filename << endl;
            i++;
        }
        else
        {
            cout << " <文件> " << temp->filename << endl;
            j++;
        }
        temp = temp->next;
    }
    cout << "总计: "
         << "目录: " << i << "\t文件:" << j << endl;
}

//读取文件内容
void FileClass::Read()
{
    string filename;
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << "文件不存在!" << endl;
        return;
    }
    else
    {
        temp = recent->child;
        while (temp)
        {
            if (temp->filename == filename)
            {
                cout << temp->filecontent << endl;
                return;
            }
            temp = temp->next;
        }
        cout << " 文件不存在!" << endl;
    }
}

//向文件写入内容
void FileClass::Write()
{
    string filename;
    cin >> filename;
    if (recent->child == NULL)
    {
        cout << "文件不存在!" << endl;
        return;
    }
    else
    {
        temp = recent->child;
        while (temp != NULL)
        {
            if (temp->filename == filename)
            {
                recent->opened = 1; //设置文件标记为打开
                cin >> temp->filecontent;
                recent->opened = 0; //设置文件标记为关闭
                cout << "文件写入成功!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "文件不存在!" << endl;
    }
}

//删除文件或目录
void FileClass::Del()
{
    string filename;
    cin >> filename;
    if (recent->child != NULL)
    {
        temp = recent->child;
        while (temp->next && temp->filename != filename)
            temp = temp->next;
        if (temp->filename != filename)
        {
            cout << " 不存在该文件!" << endl;
            return;
        }
    }
    else
    {
        cout << " 不存在该文件! " << endl;
        return;
    }
    if (temp->parent == NULL)
    {
        temp->pre->next = temp->next;
        if (temp->next)
            temp->next->pre = temp->pre;
        temp->pre = temp->next = NULL;
    }
    else
    {
        if (temp->next)
            temp->next->parent = temp->parent;
        temp->parent->child = temp->next;
    }
    delete temp;
    cout << "文件已删除!" << endl;
}

//切换目录
void FileClass::Cd()
{
    string topara;
    cin >> topara;
    if (topara == "..")
    {
        int i;
        while (recent->pre)
            recent = recent->pre;
        if (recent->parent)
            recent = recent->parent;
        i = para.length();
        while (para[i] != '/' && i > 0)
            i--;
        if (i != 0)
            para[i] = '\0';
        else
            para[i + 1] = '\0';
    }
    else
        FindPara(topara);
}

//寻找当前路径的父路径和祖先路径
void FileClass::FindPara(string topara)
{
    int i = 0;
    int sign = 1;
    if (topara == "/")
    {
        recent = root;
        para = "/";
        return;
    }
    temp = recent;
    temppara = para;
    if (topara[0] == '/')
    {
        recent = root->child;
        i++;
        para = "/";
    }
    else
    {
        if (recent != NULL && recent != root)
            para += "/";
        if (recent && recent->child)
        {
            if (recent->isdir)
                recent = recent->child;
            else
            {
                cout << "路径错误!" << endl;
                return;
            }
        }
    }
    while (i <= signed(topara.length()) && recent)
    {
        int j = 0;
        if (topara[i] == '/' && recent->child)
        {
            i++;
            if (recent->isdir)
                recent = recent->child;
            else
            {
                cout << "路径错误!" << endl;
                return;
            }
            para += "/";
        }
        char str[20];
        strcpy(str, topara.c_str());
        recentpara = strtok(str, "/");
        // while (topara.c_str()[i] != '/' && i <= signed(topara.length()))
        // {
        //     recentpara.c_str()[j] = topara.c_str()[i];
        //     i++;
        //     j++;
        // }
        // recentpara[j] = '\0';
        i++;
        cout << recentpara << endl;
        while ((recent->filename != recentpara || (recent->isdir != 1)) &&
               recent->next != NULL)
        {
            recent = recent->next;
        }
        if (recent->filename == recentpara)
        {
            if (recent->isdir == 0)
            {
                para = temppara;
                recent = temp;
                cout << " 是文件不是目录。\n";
                return;
            }
            para += recent->filename;
        }
        if (recent->filename != recentpara || recent == NULL)
        {
            para = temppara;
            recent = temp;
            cout << " 输入路径错误\n";
            return;
        }
    }
}

//帮助函数
void FileClass::Help()
{
    cout << "\t\t\t=====================帮助命令一览====================\n";
    cout << "\t\t\t*                                                   *\n";
    cout << "\t\t\t*          1>. create: 创建文件                     *\n";
    cout << "\t\t\t*          2>. read: 读取文件                       *\n";
    cout << "\t\t\t*          3>. write: 写入文件                      *\n";
    cout << "\t\t\t*          4>. del : 删除文件                       *\n";
    cout << "\t\t\t*          5>. mkdir: 建立目录                      *\n";