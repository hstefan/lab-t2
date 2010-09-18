#ifndef HUGO_TABELAS_H__
#define HUGO_TABELAS_H__

#include "banco.h"
#include "registro.h"
#include "list.h"
#include "dados.h"

namespace base
{
	using data::Registro;
	using bd::Tabela;
	using ds::list;
	using namespace base;

	class RegistroIncompativelException
	{
	public:
		RegistroIncompativelException(const Registro* reg);
		const Registro* getRegistro() const
		{ return registro; }
	private:
		const Registro* registro;
	};

	class Alunos : public Tabela
	{
	public:
		Alunos();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);

	protected:
		typedef list<Aluno>::iterator AlunoIter;
		AlunoIter search(const Aluno& aluno);

	private:
		list<Aluno> alunos;
	};

	class Professores : public Tabela
	{
	public:
		Professores();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);
	
	private:
		list<Professor> alunos;
	};

	class Turmas : public Tabela
	{
	public:
		Turmas();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);
	
	private:
		list<Turma> alunos;
	};
}


#endif