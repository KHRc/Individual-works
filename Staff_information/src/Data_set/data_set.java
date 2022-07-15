package Data_set;

public class data_set {
	//显示
		public void display(Connection c)throws Exception {
			
		Statement stmt=c.createStatement();
	 
	  //ResultSet : 结果集对象 (指的是一个select语句的查询结果)

		ResultSet rs=stmt.executeQuery("select T_teacher.教工编号,姓名,性别,出生年月,所在学院,T_inst.学院名称\r\n" + 
				"from T_teacher left join T_inst on T_teacher.所在学院=T_inst.学院代码");
		System.out.println("教工编号"+"\t"+"\t"+"姓名"+"\t"+"性别"+"\t"+"出生年月"+"\t"+"\t"+"所在学院"+"\t"+"学院名称");
	    while (rs.next()) {
	    	for (int i=1;i<7;i++) {
	    		String s=rs.getString(i);
	    		System.out.print(s);
	    		System.out.print("\t");
	    	} System.out.print("\n");
	    }
	   
	    stmt.close();
	    c.close();
		}


		//插入
		public void Insert(Connection c)throws Exception {
			System.out.print("输入需要的内容:\n");
			Scanner input = null;
			String ID,name,sex,date,inst;
			input =new Scanner(System.in);
			ID=input.next();
			input =new Scanner(System.in);
			name=input.next();
			input =new Scanner(System.in);
			sex=input.next();
			input =new Scanner(System.in);
			date=input.next();
			input =new Scanner(System.in);
			inst=input.next();
			
			String SqlOrder="INSERT INTO T_teacher VALUES("
		              +ID+",'"+name+"','"+sex+"',"+date+","+inst+")";
			Statement stmt=c.createStatement();
			int rs=stmt.executeUpdate(SqlOrder);
			System.out.print("成功插入行数： "+rs);
			System.out.print("\n ");
		    stmt.close();
		    c.close();
		    //input.close();
		}


		//修改
		public void Update(Connection c)throws Exception{
			System.out.print("输入需要修改的员工编号\n");
			Scanner input =new Scanner(System.in);
			String temp=input.next();
			System.out.print("需要修改第几列\n");
			Scanner input1 =new Scanner(System.in);
			int t=input1.nextShort();
			System.out.print("需要修改的值\n");
			Scanner input2 =new Scanner(System.in);
			String SqlOrder="";
			String Value;
			switch(t) {
			case 1:
				Value=input2.next();
				SqlOrder="UPDATE T_teacher SET 教工编号 ="+Value+"where 教工编号="+temp;
				break;
			case 2:	
				Value=input2.next();
				SqlOrder="UPDATE T_teacher SET 姓名 ="+Value+"where 教工编号="+temp;
				break;
			case 3:	
				Value=input2.next();
				SqlOrder="UPDATE T_teacher SET 性别 ="+Value+"where 教工编号="+temp;
				break;
			case 4:	
				Value=input2.next();
				SqlOrder="UPDATE T_teacher SET 出生年月 ="+Value+"where 教工编号="+temp;
				break;
			case 5:	
				Value=input2.next();
				SqlOrder="UPDATE T_teacher SET 所在学院 ="+Value+"where 教工编号="+temp;
				break;
			default:
			     System.out.print("输入错误,已退出");
			     break ;
			}
			input2.close();
			input1.close();
			Statement stmt=c.createStatement();
			int rs=stmt.executeUpdate(SqlOrder);
			System.out.print("成功修改的行数： "+rs);
			System.out.print("\n");
			input.close();
		    stmt.close();
		    c.close();
		}


		//删除
		public void Delete(Connection c)throws Exception {
			System.out.print("输入删除的员工编号\n");
			Scanner input =new Scanner(System.in);
			String temp=input.next();
			String SqlOrder="DELETE FROM T_teacher WHERE 教工编号="+temp;
			Statement stmt=c.createStatement();
			int rs=stmt.executeUpdate(SqlOrder);
			System.out.print("成功删除行数： "+rs);
			//input.close();
		    stmt.close();
		    c.close();
		}
		
		//查询
		public void query(Connection c)throws Exception {	
		System.out.print("输入需要查询的员工编号\n");
		Scanner input =new Scanner(System.in);
		String temp=input.next();
		Statement stmt=c.createStatement();
		ResultSet rs=stmt.executeQuery("select T_teacher.教工编号,姓名,性别,出生年月,所在学院,T_inst.学院名称\r\n" + 
				"from T_teacher left join T_inst on T_teacher.所在学院=T_inst.学院代码\r\n" + 
				"where T_teacher.教工编号="+temp);
		System.out.println("教工编号"+"\t"+"\t"+"姓名"+"\t"+"性别"+"\t"+"出生年月"+"\t"+"\t"+"所在学院"+"\t"+"学院名称");
	    while (rs.next()) {
	    	for (int i=1;i<7;i++) {
	    		String s=rs.getString(i);
	    		System.out.print(s);
	    		System.out.print("\t");
	    	} System.out.print("\n");
	    }
	    }




}
