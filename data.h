#ifndef HUGO_DATA_H__
#define HUGO_DATA_H__

#include <string>
#include "secondary_data.h"

namespace base
{
	class Aluno
	{
	public:
		
	private:
		unsigned int matricula;
		std::string nome;
		aux::Endereco endereco;
	};

	class Professor;
	class Disciplina;
	class Turma;
	class Avaliacao;
}

#endif