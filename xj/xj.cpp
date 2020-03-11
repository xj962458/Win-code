void CdialogDlg::OnBnClickedButtonsubmit()
{
    CString msg = "";
    CString major;
    UpdateData(TRUE);

    msg = msg + "姓名：" + name;
    msg = msg + "\n性别：" + (this->int_sex == 0 ? "男" : "女");
    this->cbx_major.GetWindowTextA(major);
    msg += "\n专业：" + major;
    msg += "\n爱好：";
    CButton *pBtn = (CButton *)GetDlgItem(IDC_CHECK_basketball);
    if (pBtn->GetCheck())
        msg += "篮球";
    pBtn = (CButton *)GetDlgItem(IDC_CHECK_network);
    if (pBtn->GetCheck())
        msg += "上网";
    pBtn = (CButton *)GetDlgItem(IDC_CHECK_tour);
    if (pBtn->GetCheck())
        msg += "旅游";
    pBtn = (CButton *)GetDlgItem(IDC_CHECK_game);
    if (pBtn->GetCheck())
        msg += "游戏";

    MessageBox(msg, "信息");
}
