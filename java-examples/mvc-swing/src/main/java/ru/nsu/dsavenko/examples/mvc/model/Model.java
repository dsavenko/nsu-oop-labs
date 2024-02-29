package ru.nsu.dsavenko.examples.mvc.model;
public class Model implements AutoCloseable {

    private final long timeout = 5000;
    private int a;
    private int b;
    private Thread thread;
    private ModelListener listener;
    private State state = State.NO_ANSWER;

    public Model() {
        thread = new Ticker(this);
        thread.start();
        generate();
    }

    synchronized void generate() {
        a = (int) (Math.random() * 100);
        b = (int) (Math.random() * 100);
        state = State.NO_ANSWER;
        notifyUnsafe();
    }

    private void notifyUnsafe() {
        if (null != listener) {
            listener.onModelChanged();
        }
    }

    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    public State getState() {
        return state;
    }

    public long getTimeout() {
        return timeout;
    }

    public synchronized void setUserAnswer(int x) {
        state = x == a + b ? State.USER_RIGHT : State.USER_WRONG;
        notifyUnsafe();
    }

    public synchronized void setWrongInput() {
        state = State.INPUT_MISMATCH;
        notifyUnsafe();
    }

    public synchronized void setListener(ModelListener listener) {
        this.listener = listener;
    }

    @Override
    public void close() throws InterruptedException {
        thread.interrupt();
        thread.join();
    }
}
