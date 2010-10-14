#ifndef HUGO_REGISTRO_H__
#define HUGO_REGISTRO_H__

#include <string>
#include <ostream>

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

		virtual void print(std::ostream& os) const
		{
			os << "Nome da tabela: " << nome_tabela << std::endl;
			os << "Codigo do item: " << codigo << std::endl;
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

inline std::ostream& operator<< (std::ostream& stream, const data::Registro& reg)
{
	reg.print(stream);
	return stream;
}

#endif