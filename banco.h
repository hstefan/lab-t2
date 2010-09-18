#ifndef HUGO_BANCO_H__
#define HUGO_BANCO_H__

#include "registro.h"
#include "list.h"
#include <string>

namespace bd
{
	using data::Registro;

	class Tabela
	{
	public:
		Tabela(const std::string& table_name);
		virtual void store(Registro* reg) = 0;
		virtual void remove(Registro* reg) = 0;
		virtual void update(Registro* reg) = 0;

		const std::string& table_name() const;

	private:
		std::string name;
	};

	class Banco
	{
	public:
		static Banco& getInstance()
		{ return _instance; }

		void registerTable(Tabela* table);
		void deleteTable(const std::string& name);
		void save(const std::string& table, Registro* reg);
		void sync(const std::string& table, Registro* reg);
		void erase(const std::string& table, Registro* reg);
	private:
		Banco() 
		{ }
		~Banco()
		{ }
		Banco(const Banco&);
		Banco& operator=(const Banco&);

		typedef ds::list<Tabela*>::iterator TabelaIter;
		TabelaIter searchTable(const std::string& name);

		static Banco _instance;
		ds::list<Tabela*> tabelas;
	};
}

#endif