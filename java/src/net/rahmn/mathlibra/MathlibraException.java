package net.rahmn.mathlibra;

/**
 * Created by raven on 2016-01-26.
 */
public class MathlibraException extends Exception {
    private String desc;
    private String type;
    private short id;

    public MathlibraException(String desc) {
        this.id = 0;

        this.type = "Unset";
        this.desc = desc;
    }

    public MathlibraException(String desc, String type) {
        this.id = 0;
        this.desc = desc;
        this.type = type;
    }

    public MathlibraException(String desc, String type, short id) {
        this.desc = desc;
        this.type = type;
        this.id = id;
    }

    @Override
    public String toString() {
        return "[" + type + "](" + id + ") " + desc;
    }

    public short getId() {
        return id;
    }

    public String getType() {
        return type;
    }

    public String getDesc() {
        return desc;
    }
}
