#ifndef COMPLIANT_MISC_BENCHMARK_H
#define COMPLIANT_MISC_BENCHMARK_H

#include "../initCompliant.h"
#include <sofa/core/objectmodel/BaseObject.h>

#include <Eigen/Core>
#include <boost/chrono.hpp>

namespace sofa {
namespace component {
namespace linearsolver {

class AssembledSystem;
class Response;

class SOFA_Compliant_API Benchmark : public core::objectmodel::BaseObject {

  public:

	// TODO maybe add a 'size' data to hold vector size. 'clear'
	// should not dealloc/realloc, so we should be fine.
	
	// duration
	Data<SReal> factor;
	
	// convergence
	Data< vector<SReal> > dual, primal, complementarity, duration;
	
	typedef SReal real;
	typedef Eigen::Matrix<real, Eigen::Dynamic, 1> vec;

    SOFA_CLASS(Benchmark, core::objectmodel::BaseObject);

	Benchmark();

	// clear benchmark data. call this at the beginning of solve.
	void clear();
	
	// 
	void debug() const;

    // restart timer and return elapsed microseconds since last call
	unsigned restart();

	// microseconds elapsed since last restart call
	unsigned elapsed() const;

	// push the results for the last iteration, including elapsed
	// time, for an LCP solver
	void lcp(const AssembledSystem& system, 
			 const vec& rhs,	// the lcp rhs: b - J Minv f
			 const Response& response, 
			 const vec& dual); 
	
	// push the results for the last iteration, including elapsed
	// time, for a QP solver
	void qp(const AssembledSystem& system, 
			const vec& rhs,
			const vec& x);

	// convenience scoped timing tool
	struct scoped_timer {
		Benchmark* bench;
		Data<SReal> Benchmark::* member;

		// write elapsed time to member pointer on destruction
		scoped_timer(Benchmark* bench,
					 Data<SReal> Benchmark::* member)
			: bench(bench),
			  member(member) {
			if( bench ) bench->restart();
		}

		~scoped_timer() {
			if( bench ) {

				(bench->*member).setValue( bench->restart() );
			}
		}

	};

  protected:
	
	typedef boost::chrono::high_resolution_clock clock_type;
	clock_type::time_point last;

	void push(const vec& primal, const vec& dual);
	
};



}
}
}


#endif