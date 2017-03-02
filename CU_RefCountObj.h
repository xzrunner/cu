#ifndef _CLASS_UTILITY_REF_COUNT_OBJ_H_
#define _CLASS_UTILITY_REF_COUNT_OBJ_H_

namespace cu
{

class RefCountObj
{
public:
	RefCountObj();
	RefCountObj(const RefCountObj& obj);
	RefCountObj& operator = (const RefCountObj& obj);
	virtual ~RefCountObj() = 0;

	virtual void AddReference() const;
	virtual void RemoveReference() const;

	int GetRefCount() const { return m_ref_count; }

private:
	mutable int m_ref_count;

}; // RefCountObj

template<class T>
struct AddRefFunctor
{
	void operator()(const T* p) const {
		p->AddReference();
	}
}; // AddRefFunctor

template<class T>
struct RemoveRefFunctor
{
	void operator()(const T* p) const {
		p->RemoveReference();
	}
}; // RemoveRefFunctor

template<class T>
void RefCountObjAssign(const T*& left, const T*& right)
{
	if (left != right) {
		if (left) {
			left->RemoveReference();
		}
		left = right;
		if (right) {
			right->AddReference();
		}
	}
}

template<class T>
void RefCountObjAssign(T*& left, T*& right)
{
	if (left != right) {
		if (left) {
			left->RemoveReference();
		}
		left = right;
		if (right) {
			right->AddReference();
		}
	}
}

template<class T>
void RefCountObjAssign(T*& left, T* const & right)
{
	if (left != right) {
		if (left) {
			left->RemoveReference();
		}
		left = right;
		if (right) {
			right->AddReference();
		}
	}
}

}

#include "CU_RefCountObj.inl"

#endif // _CLASS_UTILITY_REF_COUNT_OBJ_H_