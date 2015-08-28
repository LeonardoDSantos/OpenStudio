/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef MODEL_ZONEMIXING_IMPL_HPP
#define MODEL_ZONEMIXING_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/ModelObject_Impl.hpp>

namespace openstudio {
namespace model {

class ThermalZone;
class Schedule;

namespace detail {

  /** ZoneMixing_Impl is a ModelObject_Impl that is the implementation class for ZoneMixing.*/
  class MODEL_API ZoneMixing_Impl : public ModelObject_Impl {

   public:
    /** @name Constructors and Destructors */
    //@{

    ZoneMixing_Impl(const IdfObject& idfObject,
                    Model_Impl* model,
                    bool keepHandle);

    ZoneMixing_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                    Model_Impl* model,
                    bool keepHandle);

    ZoneMixing_Impl(const ZoneMixing_Impl& other,
                    Model_Impl* model,
                    bool keepHandle);

    virtual ~ZoneMixing_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const override;

    //@}
    /** @name Getters */
    //@{

    ThermalZone zone() const;
    
    Schedule schedule() const;

    std::string designFlowRateCalculationMethod() const;

    boost::optional<double> designFlowRate() const;

    boost::optional<double> flowRateperZoneFloorArea() const;

    boost::optional<double> flowRateperPerson() const;

    boost::optional<double> airChangesperHour() const;

    boost::optional<ThermalZone> sourceZone() const;

    boost::optional<double> deltaTemperature() const;

    boost::optional<Schedule> deltaTemperatureSchedule() const;

    boost::optional<Schedule> minimumZoneTemperatureSchedule() const;

    boost::optional<Schedule> maximumZoneTemperatureSchedule() const;

    boost::optional<Schedule> minimumSourceZoneTemperatureSchedule() const;

    boost::optional<Schedule> maximumSourceZoneTemperatureSchedule() const;

    boost::optional<Schedule> minimumOutdoorTemperatureSchedule() const;

    boost::optional<Schedule> maximumOutdoorTemperatureSchedule() const;

    //@}
    /** @name Setters */
    //@{

    bool setSchedule(Schedule& schedule);

    bool setDesignFlowRate(double designFlowRate);

    bool setFlowRateperZoneFloorArea(double flowRateperZoneFloorArea);

    bool setFlowRateperPerson(double flowRateperPerson);

    bool setAirChangesperHour(double airChangesperHour);

    bool setSourceZone(const ThermalZone& zone);

    void resetSourceZone();

    void setDeltaTemperature(double deltaTemperature);

    void resetDeltaTemperature();

    bool setDeltaTemperatureSchedule(Schedule& schedule);

    void resetDeltaTemperatureSchedule();

    bool setMinimumZoneTemperatureSchedule(Schedule& schedule);

    void resetMinimumZoneTemperatureSchedule();

    bool setMaximumZoneTemperatureSchedule(Schedule& schedule);

    void resetMaximumZoneTemperatureSchedule();

    bool setMinimumSourceZoneTemperatureSchedule(Schedule& schedule);

    void resetMinimumSourceZoneTemperatureSchedule();

    bool setMaximumSourceZoneTemperatureSchedule(Schedule& schedule);

    void resetMaximumSourceZoneTemperatureSchedule();

    bool setMinimumOutdoorTemperatureSchedule(Schedule& schedule);

    void resetMinimumOutdoorTemperatureSchedule();

    bool setMaximumOutdoorTemperatureSchedule(Schedule& schedule);

    void resetMaximumOutdoorTemperatureSchedule();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:

   private:

    REGISTER_LOGGER("openstudio.model.ZoneMixing");

  };

} // detail

} // model
} // openstudio

#endif // MODEL_ZONEMIXING_IMPL_HPP
