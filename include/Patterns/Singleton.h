//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_SINGLETON_H
#define AVR_PROTO_LINUX_SINGLETON_H


//В конструкторе ничего не должно быть !
template <class T>
class Singleton {
private:
    static T* object;
    public:
    Singleton() = default;

    static T* getObject() {
        if (!object) {
            object = new T;
        }
        return object;
    }
};

//Хз почему я не могу объявить статическуб пеменную внутри класс
template <class T>
T* Singleton<T>::object = nullptr;

#endif //AVR_PROTO_LINUX_SINGLETON_H
