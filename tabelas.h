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
		typedef list<Aluno>::iterator AlunoIter;
		Alunos();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);

		Aluno* getAluno(unsigned int matricula);
		AlunoIter begin() const;
		AlunoIter end() const;

	protected:
		AlunoIter search(const Aluno& aluno);

	private:
		list<Aluno> alunos;
	};

	class Professores : public Tabela
	{
	public:
		typedef list<Professor>::iterator ProfIter;
		Professores();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);
		
		Professor* getProfessor(const std::string& siape);
		ProfIter begin() const;
		ProfIter end() const;
	protected:
		ProfIter search(const Professor& prof);
	private:
		list<Professor> professores;
	};

	class Turmas : public Tabela
	{
	public:
		Turmas();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);
	
	protected:
		typedef list<Turma>::iterator TurmaIter;
		TurmaIter search(const Turma& turma);
	private:
		list<Turma> turmas;
	};

	class Cursos : public Tabela
	{
	public:
		Cursos();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);

		Curso* getCurso(const std::string& codigo);
		typedef list<Curso>::iterator CursoIter;

		inline CursoIter begin()
		{
			return cursos.begin();
		}
		inline CursoIter end()
		{
			return cursos.end();
		}
	protected:
		CursoIter search(const Curso& curso);
	private:
		list<Curso> cursos;
	};
}


#endif