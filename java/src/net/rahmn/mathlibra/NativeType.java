package net.rahmn.mathlibra;

/**
 * Created by raven on 2016-01-26.
 */
public class NativeType  implements AutoCloseable{

    /**
     * Native interaction
     */
    private long __handle;
    private static native long copyInstance(long handle);
    private static native void freeInstance(long handle);
    /**
     *
     */
    public native int        sizeN();
    public native int        sizeM();
    public native boolean    isVector();
    public native boolean    isList() ;
    public native boolean    isSingleton();
    public native boolean    isString();
    public native boolean    isNumber() ;
    /*
     *  Tries to convert the object to an number,
     *
     */
    private native double  toNumberN();
    public  double toNumber() throws MathlibraException
    {
        if(!isNumber())
            throw new MathlibraException("Object not convertable to doulbe");
        else return toNumberN();
    }
    @Override
    public native String  toString();

    /*
     * This constructor is only for implementing the backend,
     * and should never be used by the end user.
     */
    public NativeType(long handle) throws MathlibraException {
        this.__handle = copyInstance(handle);
    }
    public NativeType(long handle,boolean copy) throws MathlibraException
    {
        if(copy)
        {
            this.__handle=copyInstance(handle);
        }
        else
        {
            this.__handle=handle;
        }
    }
    public native Object getObj();
    protected void finalize() throws Exception
    {
        if(__handle!=0)
        {
            close();
        }
    }
    /*
     * Frees the native component of NativeType.
     * Used to explicitly free the memory of the object. After an call to this method the object is in an invalid state,
     * thus further methods calls is illegal.
     */
    @Override
    public void close()
    {
        freeInstance(__handle);
        __handle=0;
    }
}
