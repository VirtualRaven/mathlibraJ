package net.rahmn.mathlibra;

/**
 * Created by raven on 2016-02-01.
 */
public class FunctionData {


    @Override
    public String toString() {
        return "FunctionData{" +
                "name='" + name + '\'' +
                ", tag='" + tag + '\'' +
                ", doc='" + doc + '\'' +
                ", displayName='" + displayName + '\'' +
                ", signature='" + signature + '\'' +
                '}';
    }

    public FunctionData(String name, String tag, String doc, String displayName,String signature) {
        this.name = name;
        this.tag = tag;
        this.doc = doc;
        this.displayName = displayName;
        this.signature = signature;
    }

    public String name;
    public String tag;
    public String doc;
    public String displayName;
    public String signature;
}
