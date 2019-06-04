// Original Source Code by Meroni,
// https://github.com/Flowx08/artificial_intelligence
// Modified by Curtó & Zarza
// {curto,zarza}.2@my.cityu.edu.hk

#ifndef COST_HPP
#define COST_HPP

////////////////////////////////////////////////////////////
///	INCLUDES
////////////////////////////////////////////////////////////
#include "../util/Tensor.hpp"
#include "../util/Macros.hpp"
#ifdef CUDA_BACKEND
#include "../util/CUDA_Tensor.hpp"
#endif

////////////////////////////////////////////////////////////
///	NAMESPACE LG
////////////////////////////////////////////////////////////
namespace lg
{
	
	////////////////////////////////////////////////////////////
	/// \brief	A function that returns a number representing how
	/// well the neural network performed to map inputs and outputs
	///
	////////////////////////////////////////////////////////////
	class Cost
	{
		public:

			//Cost function types
			enum CostType
			{
				SquaredError = 0,
				CrossEntropy = 1,
			};

			////////////////////////////////////////////////////////////
			/// \brief	Default constructor	
			///
			////////////////////////////////////////////////////////////
			Cost();

			////////////////////////////////////////////////////////////
			/// \brief	Construct from cost function type	
			///
			////////////////////////////////////////////////////////////
			Cost(const CostType type);

			#ifdef CUDA_BACKEND
			
			////////////////////////////////////////////////////////////
			/// \brief	Calculate errors
			///
			////////////////////////////////////////////////////////////
			float getErrorcuda(CUDA_Tensor_float& prediction, CUDA_Tensor_float& target);

			////////////////////////////////////////////////////////////
			/// \brief	Calculate deltas
			///
			////////////////////////////////////////////////////////////
			void getDeltacuda(CUDA_Tensor_float& prediction, CUDA_Tensor_float& target, CUDA_Tensor_float& errors);

			#else
			
			////////////////////////////////////////////////////////////
			/// \brief	Calculate errors
			///
			////////////////////////////////////////////////////////////
			float getError(Tensor_float& prediction, Tensor_float& target);

			////////////////////////////////////////////////////////////
			/// \brief	Calculate deltas
			///
			////////////////////////////////////////////////////////////
			void getDelta(Tensor_float& prediction, Tensor_float& target, Tensor_float& errors);

			#endif

		private:
			CostType _type;
			#ifdef CUDA_BACKEND
			CUDA_Tensor_float _gpu_errors;
			Tensor_float _host_errors;
			#endif
	};

} //namespace lg

#endif /* end of include guard: COST_HPP */

