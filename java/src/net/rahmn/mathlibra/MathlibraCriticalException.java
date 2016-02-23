package net.rahmn.mathlibra;

/**
 * Created by raven on 2016-02-01.
 */
public class MathlibraCriticalException extends MathlibraException {

    public MathlibraCriticalException(String desc, String type, short id) {
        super(desc, type, id);
    }

    public MathlibraCriticalException(String desc, String type) {
        super(desc, type);
    }

    public MathlibraCriticalException(String desc) {
        super(desc);
    }
}
