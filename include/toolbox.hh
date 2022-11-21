#ifndef TOOLBOX_HH
#define TOOLBOX_HH

#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


#include "common.hh"
#include <iomanip>

namespace toolbox{

  inline std::string int_to_string( int64_t val ){
    std::stringstream out;
    out << std::setw(10) << std::setfill('0') << val;
    return out.str();
  }

  // Originally included functions
  void drawOptFlowMap(const cv::Mat& flow, cv::Mat& cflowmap, int step, const cv::Scalar& color);
  void convertFlowToImage(const cv::Mat &flow_x, const cv::Mat &flow_y, cv::Mat &img_x, cv::Mat &img_y,
         double lowerBound, double higherBound, bool finegrained = false );

  // Encodes cv::Mat as jpeg and converts to string (and reverse)
  std::string encode( const cv::Mat & m );
  cv::Mat decode( std::string & str, bool is_color = false );


  class IOManager{
    public:
      IOManager(  const std::string img, const std::string flow_x, const std::string flow_y);


      void WriteImg( const cv::Mat & img, const int64_t id );
      void WriteFlow( const cv::Mat & x, const cv::Mat & y, const int64_t id);


    private:
      std::string CreateFilename( const int64_t id, const int64_t type );
      std::string img_;
      std::string flow_x_;
      std::string flow_y_;


  };

} // namespace toolbox
#endif
