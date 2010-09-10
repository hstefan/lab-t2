#ifndef HUGO_DATA_H__
#define HUGO_DATA_H__

#include <string>
#include "secondary_data.h"
#include "list.h"

namespace base
{
	class Aluno;
	class Professor;
	class Disciplina;
	class Turma;
	class Avaliacao;
	class Curso;

	class Aluno
	{
	public:
		Aluno(const Curso* curso, unsigned int matricula, const std::string& nome);

		const Curso& getCurso() const;
		unsigned int getMatricula() const;
		const std::string& getNome() const;
		void setCurso(Curso* curso);
		void setMatricula(unsigned int matricula);
		void setNome(const std::string& nome);
	private:
		const Curso* curso;
		unsigned int matricula;
		std::string nome;
	};

	class Professor
	{
	public:
		Professor(const std::string& siape, const std::string& nome, const std::string& area, const std::string& titulacao);
		
		void setSiape(const std::string& siape);
		void setNome(const std::string& nome);
		void setArea(const std::string& area);
		void setTitulacao(const std::string& titulacao);
		const std::string& getSiape() const;
		const std::string& getNome() const;
		const std::string& getArea() const;
		const std::string& getTitulacao() const;
	private:
		std::string siape;
		std::string nome;
		std::string area;
		std::string titulacao;
	};

	class Disciplina
	{
	public:
		typedef ds::list<const Disciplina*>::iterator DiscIterator;

		Disciplina(const std::string& codigo, Curso* curso, const std::string& nome, 
			unsigned int carga, const ds::list<Disciplina>& requisitos = ds::list<Disciplina>());

		void setCodigo(const std::string codigo);
		void setCurso(Curso* curso);
		void setNome(const std::string& nome);
		void setCarga(unsigned int carga);
		
		template <class InputIterator>
		  void setRequisitos(InputIterator begin, InputIterator end);
		
		const std::string& getCodigo() const;
		const Curso& getCurso() const;
		const std::string& getNome() const;
		unsigned int getCarga() const;
		DiscIterator getRequisitosBeginIter() const;
		DiscIterator getRequisitosEndIter() const;

		void adcionaRequisito(const Disciplina* disciplina);
		void removeRequisito(const Disciplina* disciplina);
		void removeRequisito(const DiscIterator disciplina);
	private:
		std::string codigo;
		const Curso* curso;
		std::string nome;
		unsigned int carga;
		ds::list<const Disciplina*> requistos; 
	};

	class Turma
	{
	public:
		typedef ds::list<const Aluno*>::iterator AlunosIter;
		typedef ds::list<const Professor*>::iterator ProfessoresIter;
		
		Turma(const Curso* curso, const ds::list<Aluno>& alunos, const ds::list<Aluno>& professores);

		AlunosIter getAlunosBegin();
		AlunosIter getAlunosEnd();
		ProfessoresIter getProfessoresBegin();
		ProfessoresIter getProfessoresEnd();
		const Curso&  getCurso();

		template <class InputIterator>
		  void setAlunos(InputIterator begin, InputIterator end);

		template <class InputIterator>
		  void setProfessores(InputIterator begin, InputIterator end);

		void setCurso(const Curso* curso);

		void adcionaAluno(const Aluno* aluno);
		void adcionaProfessor(const Professor* professor);
		void removerAluno(AlunosIter aluno);
		void removerProfessor(ProfessoresIter professor);
	private:
		ds::list<const Aluno*> alunos;
		ds::list<const Professor*> professores;
		const Curso* curso;
	};

	class Curso
	{
	public:
		typedef ds::list<const Turma*>::iterator TurmasIter;

		const std::string& getCodigo();
		const std::string& getNome();
		TurmasIter getTurmasBegin();
		TurmasIter getTurmasEnd();
		
		void setCodigo(const std::string& codigo);
		void setNome(const std::string& nome);
		template <class InputIterator>
		  void setTurmas(InputIterator begin, InputIterator end);

		void adcionaTurma(const Turma* turma);
		void removeTurma(const Turma* turma);
		void removeTurma(TurmasIter turma);
	private:
		std::string codigo;
		std::string nome;
		ds::list<const Turma*> turmas;
	};
}

#endif