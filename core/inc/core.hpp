#include <iostream>

// opencv
#include <opencv2/opencv.hpp>

using namespace std;



class CGenericObject
{	
public:
	enum TGenericObjectType {
		OBJECT_TYPE_FACE,
		OBJECT_TYPE_HAND,
		OBJECT_TYPE_EYE,
		OBJECT_TYPE_UNDEFINED
	};

	CGenericObject(TGenericObjectType f_objId_u):m_objId_u(f_objId_u) {
		// todo: change the number 4 to dynamic size of enum		
		m_genericObjectTypeName_v.insert(std::make_pair(TGenericObjectType::OBJECT_TYPE_FACE, "OBJECT_TYPE_FACE"));
		m_genericObjectTypeName_v.insert(std::make_pair(TGenericObjectType::OBJECT_TYPE_HAND, "OBJECT_TYPE_HAND"));
		m_genericObjectTypeName_v.insert(std::make_pair(TGenericObjectType::OBJECT_TYPE_EYE, "OBJECT_TYPE_EYE"));
		m_genericObjectTypeName_v.insert(std::make_pair(TGenericObjectType::OBJECT_TYPE_UNDEFINED, "OBJECT_TYPE_UNDEFINED"));

		// set obj name
		setObjName(f_objId_u);
	}	

	// function
	std::string getObjTypeName();

private:	
	// functions
	bool setObjName(TGenericObjectType f_objId_u);	
	

	std::map<CGenericObject::TGenericObjectType, std::string> m_genericObjectTypeName_v;
	TGenericObjectType m_objId_u;
	std::string m_objName_s;
};



bool CGenericObject::setObjName(TGenericObjectType f_objId_u)
{
	bool l_success_b = false;

	m_objName_s = m_genericObjectTypeName_v.find(f_objId_u)->second;

	if (f_objId_u > TGenericObjectType::OBJECT_TYPE_FACE && f_objId_u < TGenericObjectType::OBJECT_TYPE_UNDEFINED)
		l_success_b = true;

	return l_success_b;
}

std::string CGenericObject::getObjTypeName()
{
	return m_objName_s;
}