#include <vector>
#include <string>
#include <map>

struct NeutronEvent {
  double time;
  double tail;
  double total;
};

class RegularHistogram {
  private:
    const uint32_t bins;
    const double min, max;
    std::map<uint32_t , uint32_t> h;
    uint32_t index(double v) const { return (v - min) / (max - min); }
  public:
    RegularHistogram( uint32_t bins , double min, double max ): 
      bins(bins) , max(max) , min(min) {}
    void addValue(double v);
    void printHistogram( std::string fname ) const;

    friend class HistogramConglomerator;
};

class TimeDifferenceHistogramGenerator {
  private:
    const std::vector<const NeutronEvent> events;
  public:
    TimeDifferenceHistogramGenerator( std::string fname  );
    template< typename BooleanOperator >
    RegularHistogram histogram(uint32_t bins , BooleanOperator cutoff , double max,  double min = 0);
};
