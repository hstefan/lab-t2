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
		typedef list<Turma>::iterator TurmaIter;
		Turmas();
		virtual void store(Registro* reg);
		virtual void remove(Registro* reg);
		virtual void update(Registro* reg);
		
		inline TurmaIter begin() const
		{
			return turmas.begin();
		}
		inline TurmaIter end() const
		{
			return turmas.end();
		}

		Turma* getTurma(const std::string& cod_curso, const std::string& cod_turma);
	protected:
		TurmaIter search(const Turma& turma);
	private:
		list<Turma> turmas;
	};

	class Cursos : public Tabela
	{
	public:
		Cursos();
		void store(Registro* reg);
		void remove(Registro* reg);
		void update(Registro* reg);

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

	class Disciplinas : public Tabela
	{
	public:
		Disciplinas();
		void store(Registro* reg);
		void remove(Registro* reg);
		void update(Registro* reg);

		Disciplina* getDisciplina(const std::string& cod_disc, const std::string& cod_curso);

		typedef list<Disciplina>::iterator DisciplinaIter;

		inline DisciplinaIter begin() const
		{
			return disciplinas.begin();
		}

		inline DisciplinaIter end() const
		{
			return disciplinas.end();
		}

	protected:
		DisciplinaIter search(const Disciplina& disc);
	private:
		list<Disciplina> disciplinas;
	};

	class Notas : public Tabela
	{
	public:
		Notas();
		void store(Registro* reg);
		void remove(Registro* reg);
		void update(Registro* reg);

		Nota* getNota(const std::string& codTurma, unsigned int mat);

		typedef list<Nota>::iterator NotaIter;

		inline NotaIter begin() const
		{
			return notas.begin();
		}

		inline NotaIter end() const
		{
			return notas.end();
		}

		class NotasTurma
		{
		public:

			NotasTurma(base::Turma* turma, const base::Notas* const notas);

			Nota::note_type calculaMedia(unsigned int mat);
			
			struct AlunoProva
			{
				Aluno* al;
				list<Nota::note_type> notas;
			};

			list<AlunoProva> notas;
			unsigned int numProvas;
		};

		NotasTurma getNotas(Turma* turma) const;

	protected:
		NotaIter search(const Nota& nota);
	private:
		friend class NotasTurma;
		list<Nota> notas;
	};
}


#endif