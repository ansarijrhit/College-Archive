package datasource;

public class LinterField {
	private String name, desc, type, signature;
	private int access;
	private Object value;
	//	int access, String name, String descriptor, String signature,
//	Object value
	private boolean isPublic;

	public LinterField(String name, String desc, String type, String signature, int access, Object value,
			boolean isPublic) {
		this.name = name;
		this.desc = desc;
		String[] typeArray = type.split("\\.");
		this.type = typeArray[typeArray.length-1].split(";")[0];
		this.signature = signature;
		this.access = access;
		this.value = value;
		this.isPublic = isPublic;
	}
	
	public String getName() {
		return name;
	}
	public String getDesc() {
		return desc;
	}
	public String getType() {
		return type;
	}
	public boolean isPublic() {
		return isPublic;
	}
	public String getSignature() {
		return signature;
	}

	public int getAccess() {
		return access;
	}

	public Object getValue() {
		return value;
	}
}
