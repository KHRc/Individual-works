package staff_information;

public class teacher {

	    private int ID;//编号
	    private String name;//姓名
	    private String sex;//性别
	private int data;//出生年月
	private int inst;//学院信息
	    
	    public teacher(){}
	    public teacher(int ID){
	        super();
	        this.ID=ID;
	    }
	    public teacher(int ID,String name,String auther,int inst,int data){
	        super();//调用父类object的无参构造方法，可以省略
	        this.ID=ID;
	        this.name=name;
	        this.sex=auther;
	        this.inst=inst;
	        this.data=data;
	    }
	 
	    public String getSex() {
	        return sex;
	    }
	 
	    public void setSex(String sex) {
	        this.sex = sex;
	    }
	 
	    public int getID() {
	        return ID;
	    }
	 
	    public void setID(int ID) {
	 
	        this.ID = ID;
	    }
	 

	    public String getName() {
	 
	        return name;
	    }
	 
	    public void setName(String name) {
	        this.name = name;
	    }
	 
	    public int getData() {
	        return data;
	    }
	 
	    public void setData(int data) {
	        this.data = data;
	    }
	 
	    public int getInst() {
	        return inst;
	    }
	 
	    public void setInst(int inst) {
	        this.inst = inst;
	    }
	 
	    @Override
	    public String toString() {
	        return "teacher{" +
	                "ID=" + ID +
	                ", name='" + name + '\'' +
	                ", sex='" + sex + '\'' +
	                ", inst=" + inst +
	                ", data=" + data +
	                '}';
	    }
	

}
