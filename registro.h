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
	protected:
		const std::string nome_tabela;
		Registro(const std::string& tab)
			: nome_tabela(tab)
		{}
	};
}

#endif