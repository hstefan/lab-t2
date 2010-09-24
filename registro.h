#ifndef HUGO_REGISTRO_H__
#define HUGO_REGISTRO_H__

#include <string>

namespace data
{
	class Registro
	{
	public:
		virtual void save() = 0;
		virtual void erase() = 0;
		virtual void sync() = 0;

		inline void setCodigoRegistro(int cod)
		{
			codigo = cod;
		}

		inline int getCodigoRegistro() const
		{
			return codigo;
		}

		static const int NAO_REGISTRADO = -1;

	protected:
		const std::string nome_tabela;
		int codigo;
		Registro(const std::string& tab)
			: nome_tabela(tab), codigo(NAO_REGISTRADO)
		{}
	};
}

#endif