void CdialogDlg::OnBnClickedButtonsubmit()
{
    CString msg = "";
    CString major;
    UpdateData(TRUE);

    msg = msg + "������" + name;
    msg = msg + "\n�Ա�" + (this->int_sex == 0 ? "��" : "Ů");
    this->cbx_major.GetWindowTextA(major);
    msg += "\nרҵ��" + major;
    msg += "\n���ã�";
    CButton *pBtn = (CButton *)GetDlgItem(IDC_CHECK_basketball);
    if (pBtn->GetCheck())
        msg += "����";
    pBtn = (CButton *)GetDlgItem(IDC_CHECK_network);
    if (pBtn->GetCheck())
        msg += "����";
    pBtn = (CButton *)GetDlgItem(IDC_CHECK_tour);
    if (pBtn->GetCheck())
        msg += "����";
    pBtn = (CButton *)GetDlgItem(IDC_CHECK_game);
    if (pBtn->GetCheck())
        msg += "��Ϸ";

    MessageBox(msg, "��Ϣ");
}
