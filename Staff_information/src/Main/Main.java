package Main;

public class Main {
	public void menu() {
		System.out.print("*******教职工基本信息管理系统********\n");
		System.out.print("*********1、显示********************\n");
		System.out.print("*********2、注册***************\n");
		System.out.print("*********3、修改***************\n");
		System.out.print("*********4、删除***************\n");
		System.out.print("*********5、查询***************\n");
		System.out.print("******************************\n");
		System.out.print("请选择对应业务序号（若想退出请输入-1）：\n");
	}
	//运用接口JDBC 与SQL sever进行连接
	public class Function {
		private Connection con;
		public  Connection getConnection()throws Exception {
		try {
			//Class.forName("sun.jdbc.obdc.JdbcOdbcDriver");
			Connection con=DriverManager.getConnection("jdbc:sqlserver://localhost:1433;DatabaseName=Teacher","mathman","mathman");
			System.out.println("连接成功！");
			return con;
		}
		catch(Exception e) {
			System.out.println("连接失败！");
			e.printStackTrace();
			return con;
		}


	public static void main(String[] args) {
		int flag=0;
		Connection conn;
		Function F=new Function();
		
		Scanner input3 = null;
		Scanner input4 = null;
		while(flag!=-1) {
			conn=F.getConnection();
			F.menu();
			input3 =new Scanner(System.in);
			int t1=input3.nextShort();
			switch(t1) {
			case 1:
				F.display(conn);
				break;
			case 2:	
				F.Insert(conn);
				break;
			case 3:	
				F.Update(conn);
				break;
			case 4:	
				F.Delete(conn);
				break;
			case 5:	
				F.query(conn);
				break;
			default:
			     System.out.print("输入错误,请重试");
			     break ;
			}
			System.out.print("若要退出，请输入 -1 :\n");
			input4 =new Scanner(System.in);
			flag=input4.nextShort();
		}
		System.out.print("程序退出，欢迎下次使用，再见！\n");
		input4.close();
		input3.close();
		System.exit(0);


	}

}
