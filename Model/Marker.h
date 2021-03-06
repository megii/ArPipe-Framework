//
//  Marker.h
//  AR
//
//  Created by Aruco team
//  http://www.uco.es/investiga/grupos/ava/node/26
//

#ifndef __AR__Marker__
#define __AR__Marker__

#include <iostream>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "cameraparameters.h"

using namespace std;
namespace ArPipe {
    /**\brief This class represents a marker. It is a vector of the fours corners ot the marker
     *
     * this Class is taken from Aruco framework. Thanks
     * http://www.uco.es/investiga/grupos/ava/node/26
     * 
     */
    class Marker : public std::vector<cv::Point2f>
    {
    public:
        //id of  the marker
        int id;
        //size of the markers sides in meters
        float ssize;
        //matrices of rotation and translation respect to the camera
        cv::Mat Rvec,Tvec;
        
        /**
         */
        Marker();
        
        /**
         */
        Marker(const Marker &M);
        
        /**
         */
        Marker(const  std::vector<cv::Point2f> &corners,int _id=-1);
        
        /**
         */
        ~Marker() {}
        
        /**Indicates if this object is valid
         */
        bool isValid()const{return id!=-1 && size()==4;}
        
        /**Draws this marker in the input image
         */
        void draw(cv::Mat &in, cv::Scalar color, int lineWidth=1,bool writeId=true)const;
        
        /**Calculates the extrinsics (Rvec and Tvec) of the marker with respect to the camera
         * @param markerSize size of the marker side expressed in meters
         * @param CP parmeters of the camera
         */
        void calculateExtrinsics(float markerSize,const aruco::CameraParameters &CP)throw(cv::Exception);
        
        /**Calculates the extrinsics (Rvec and Tvec) of the marker with respect to the camera
         * @param markerSize size of the marker side expressed in meters
         * @param CameraMatrix matrix with camera parameters (fx,fy,cx,cy)
         * @param Distorsion matrix with distorsion parameters (k1,k2,p1,p2)
         */
        void calculateExtrinsics(float markerSize,cv::Mat  CameraMatrix,cv::Mat Distorsion=cv::Mat())throw(cv::Exception);
        
        /**Given the extrinsic camera parameters returns the GL_MODELVIEW matrix for opengl.
         * Setting this matrix, the reference coordinate system will be set in this marker
         */
        void glGetModelViewMatrix(  double modelview_matrix[16])throw(cv::Exception);
        
        
        /**Returns the centroid of the marker
         */
        cv::Point2f getCenter()const;
        
        /**Returns the perimeter of the marker
         */
        float getPerimeter()const;
        
        /**Returns the area
         */
        float getArea()const;
        
        /**
         */
        /**
         */
        friend bool operator<(const Marker &M1,const Marker&M2)
        {
            return M1.id<M2.id;
        }
        /**
         */
        friend ostream & operator<<(ostream &str,const Marker &M)
        {
            str<<M.id<<"=";
            for (int i=0;i<4;i++)
            str<<"("<<M[i].x<< ","<<M[i].y<<") ";
            str<<"Txyz=";
            for (int i=0;i<3;i++)
            str<<M.Tvec.ptr<float>(0)[i]<<" ";
            str<<"Rxyz=";
            for (int i=0;i<3;i++)
            str<<M.Rvec.ptr<float>(0)[i]<<" ";
            
            return str;
            }
            
            
        private:
            void rotateXAxis(cv::Mat &rotation);
            
    };
            
}
#endif /* defined(__AR__Marker__) */
