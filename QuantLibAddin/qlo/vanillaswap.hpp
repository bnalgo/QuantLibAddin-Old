
/*
 Copyright (C) 2005, 2006 Eric Ehlers
 Copyright (C) 2005 Plamen Neykov
 Copyright (C) 2005 Aurelien Chanudet

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef qla_simpleswap_hpp
#define qla_simpleswap_hpp

#include <qlo/swap.hpp>

namespace QuantLibAddin {

    class VanillaSwap : public Swap {
    public:
        VanillaSwap(
            const QuantLib::VanillaSwap::Type type,
            const QuantLib::Real nominal,
            const boost::shared_ptr<QuantLib::Schedule>& fixedSchedule,
            const QuantLib::Rate fixedRate,
            const QuantLib::DayCounter& fixDayCounter,
            const boost::shared_ptr<QuantLib::Schedule>& floatSchedule,
            const boost::shared_ptr<QuantLib::IborIndex>& index,
            const QuantLib::Spread spread,
            const QuantLib::DayCounter& floatDayCounter,
            const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS);
        VanillaSwap(
            const QuantLib::Period& swapTenor, 
            const boost::shared_ptr<QuantLib::IborIndex>& index,
            QuantLib::Rate fixedRate,
            const QuantLib::Period& forwardStart);
        std::vector<std::vector<boost::any> > fixedLegAnalysis();
        std::vector<std::vector<boost::any> > floatingLegAnalysis();
    };

}

#endif

