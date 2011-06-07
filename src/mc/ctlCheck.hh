#ifndef __CTL__CHECK__HH__
#define __CTL__CHECK__HH__


#include "ITSModel.hh"
#include "ctlp.h"


class CTLChecker {


  const its::ITSModel & model;

  /** A cache for homomorphism construction of AP */
  typedef std::map<vLabel, its::Transition> hom_map_t;
  typedef hom_map_t::const_iterator hom_map_it;
  mutable hom_map_t hom_map;

  /** A cache containing the Homomorphisms representing formulas */
  typedef std::map<Ctlp_Formula_t *, its::Transition> ctl_cache_t;
  typedef ctl_cache_t::const_iterator ctl_cache_it;
  mutable ctl_cache_t ctl_cache;
  /** A cache containing the states representing formulas */
  typedef std::map<Ctlp_Formula_t *, its::State> ctl_statecache_t;
  typedef ctl_statecache_t::const_iterator ctl_statecache_it;
  mutable ctl_statecache_t ctl_statecache;

public :
  CTLChecker (const its::ITSModel & model) : model(model) {}

  its::Transition getSelectorAP (Label apname, Label value) const;

  its::Transition getHomomorphism (Ctlp_Formula_t *formula) const;

  its::State getStateVerifying (Ctlp_Formula_t *formula) const;

  its::Transition getPredRel () const ;

  its::Transition getNextRel () const ;

  its::State getReachable () const;

  its::State getInitialState () const;

  its::State getReachableDeadlocks () const;
};



#endif
