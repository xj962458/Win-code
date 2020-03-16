CComboBox cbx_major;//专业关联的控件变量
int int_sex;        //性别关联的变量
CString name;       //姓名关联的变量

CComboBox cbx_major;//专业关联的控件变量
int int_sex;        //性别关联的变量
CString name;       //姓名关联的变量

BOOL CdialogDlg::OnInitDialog()
{
		CDialog::OnInitDialog();
	
		this->cbx_major.SetCurSel(2);//默认选择第项，即计算机

		// 将“关于...”菜单项添加到系统菜单中。
}