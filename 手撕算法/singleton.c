class singleton {
private:
    singleton(){}

    static singleton* pInstance;
public:
    static singleton* getInstance(){
        if(NULL == pInstance){
            pInstance = new singleton();
        }
        return pInstance;
    }
};