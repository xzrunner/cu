#ifndef _CLASS_UTILITY_SINGLETON_H_
#define _CLASS_UTILITY_SINGLETON_H_

#include <stddef.h>

#define CU_FLAG_METHOD(name, bit) \
	bool Is##name() const { \
		return (m_flags & bit) != 0; \
	} \
	void Set##name(bool flag) const { \
		if (flag) { \
			m_flags |= bit; \
		} else { \
			m_flags &= ~bit; \
		} \
	}

#define CU_SINGLETON_DECLARATION(name) \
	public: \
		static name* Instance(); \
	private: \
		name(); \
		~name(); \
	private: \
		static name* m_instance;

#define CU_SINGLETON_DEFINITION(name) \
	name* name::m_instance = NULL; \
	name* name::Instance() \
	{ \
		if (!m_instance) { \
			m_instance = new (name)(); \
		} \
		return m_instance; \
	}

#endif // _CLASS_UTILITY_SINGLETON_H_