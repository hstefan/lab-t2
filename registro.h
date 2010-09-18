#ifndef HUGO_REGISTRO_H__
#define HUGO_REGISTRO_H__

namespace data
{
	class Registro
	{
	public:
		virtual void save() = 0;
		virtual void erase() = 0;
		virtual void sync() = 0;
	};
}

#endif